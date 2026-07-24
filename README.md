# Wireshark Packet Analysis

## Overview

This project demonstrates basic network traffic analysis using **Wireshark**. The objective is to capture and analyze network packets, identify common protocols, examine TCP handshakes, and detect any suspicious or unusual network activity.

## Objective

- Capture network traffic using Wireshark.
- Analyze HTTP, DNS, and TCP packets.
- Understand packet structures and TCP flags.
- Identify any suspicious or malformed traffic.
- Document observations and findings.

## Tool Used

- Wireshark
- Windows Operating System

## Protocols Analyzed

### HTTP
- Captured HTTP request and response packets.
- Observed communication over TCP port 80.

### DNS
- Captured DNS queries and responses.
- Analyzed domain name resolution.
- Observed communication over UDP port 53.

### TCP
- Analyzed the TCP three-way handshake.
- Observed TCP flags:
  - SYN
  - SYN-ACK
  - ACK
  - FIN
  - RST

## Packet Structure

The following layers were examined:

- Frame Layer
- Ethernet Layer
- IP Layer
- Transport Layer (TCP/UDP)

## Findings

- Successfully captured and analyzed HTTP, DNS, and TCP traffic.
- No significant suspicious or malicious activity was detected.
- Network communication appeared normal during packet capture.

## Repository Structure

```
Wireshark-Packet-Analysis/
│── README.md
│── Report.pdf
│── Screenshots/
│   ├── http.png
│   ├── dns.png
│   ├── tcp_handshake.png
│   └── packet_details.png
```

## Screenshots

Store all Wireshark screenshots inside the **Screenshots** folder.

## Conclusion

This project provided hands-on experience with packet capture and network protocol analysis using Wireshark. It improved understanding of network communication, TCP handshakes, packet structures, and basic network security monitoring.

## Author

**Anuj Rawat**
