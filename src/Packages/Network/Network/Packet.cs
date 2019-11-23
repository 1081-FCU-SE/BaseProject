﻿using System;
using System.Net;
using System.Net.Sockets;

namespace Network.Packet {

    public class Send {

        /// <summary>
        /// 創造int封包，把int變成二進位(byte)丟給BuildPackage打包
        /// </summary>
        /// <param name="user">要發給誰</param>
        /// <param name="packageType">封包型態，發過去要幹嘛</param>
        /// <param name="Data">要發送封包的內容</param>
        public void IntPacket(User user, PackageType packageType, int Data) {
            byte[] Data_Byte = BitConverter.GetBytes(Data);     //把int Data轉成byte
            byte[] Packet = BuildPackage(user.CrcCode, packageType, user.EncryptionType, Data_Byte);
            SendPacket(user.Socket, Packet);
        }

        /// <summary>
        /// 封裝
        /// </summary>
        /// <param name="crcCode">封包驗證碼</param>
        /// <param name="packageType">封包型態</param>
        /// <param name="encryptionType">定義加密的方法</param>
        /// <param name="data_Byte">封包資料主體內容</param>
        /// <returns>回傳封裝完畢的封包</returns>
        private byte[] BuildPackage(int crcCode, PackageType packageType, EncryptionType encryptionType, byte[] data_Byte) {
            
            //using System有:BitConverter GetBytes
            //using System.Net有:IPAddress HostToNetworkOrder把後面括號內的參數轉換成網路格式
            byte[] crcCode_Byte = BitConverter.GetBytes(IPAddress.HostToNetworkOrder(crcCode));             
            byte[] packageType_Byte = BitConverter.GetBytes(IPAddress.HostToNetworkOrder((short)packageType));          //(short)強制將後面參數轉成短整數
            byte[] encryptionType_Byte = BitConverter.GetBytes(IPAddress.HostToNetworkOrder((short)encryptionType));       
            byte[] bodyLength = BitConverter.GetBytes(IPAddress.HostToNetworkOrder(data_Byte.Length));

            byte[] Packet = new byte[8 + data_Byte.Length];

            //CopyTo:把前面的內容複製到後面陣列的起始位置(陣列,起始位置)
            crcCode_Byte.CopyTo(Packet, 0);
            packageType_Byte.CopyTo(Packet, 4);
            encryptionType_Byte.CopyTo(Packet, 6);
            bodyLength.CopyTo(Packet, 8);

            return Packet;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="target"></param>
        /// <param name="Packet"></param>
        private void SendPacket(Socket target, byte[] Packet) {
            if (target.Connected) {
                try {
                    //發送資料給目標Send(封包, 長度, 起始位置)
                    target.Send(Packet, Packet.Length, 0);
                } catch(Exception ex) {
                    Console.WriteLine($"封包發送失敗： {ex.Message}");
                }
            } else {
                throw new Exception($"{target.RemoteEndPoint}： 已斷線");
            }
        }



    }

}
