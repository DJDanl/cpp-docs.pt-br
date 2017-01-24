---
title: "Estrutura WSADATA | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "WSADATA"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura WSADATA"
ms.assetid: 80cc60e5-f9ae-4290-8ed5-07003136627d
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura WSADATA
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `WSADATA` é usada para informações de inicialização de soquetes do windows de repositório retornada por uma chamada à função global de `AfxSocketInit` .  
  
## Sintaxe  
  
```  
  
      struct WSAData {  
   WORD wVersion;  
   WORD wHighVersion;  
   char szDescription[WSADESCRIPTION_LEN+1];  
   char szSystemStatus[WSASYSSTATUS_LEN+1];  
   unsigned short iMaxSockets;  
   unsigned short iMaxUdpDg;  
   char FAR * lpVendorInfo;  
};  
```  
  
#### Parâmetros  
 *wVersion*  
 A versão da especificação de soquetes do windows que a DLL de soquetes do windows aguarda o chamador usar.  
  
 *wHighVersion*  
 A versão mais recente da especificação de soquetes do windows que este DLL pode dar suporte \(também codificado como acima\).  Normalmente, esse é o mesmo que **wVersion**.  
  
 *szDescription*  
 Uma cadeia de caracteres terminada por caractere ASCII em que o DLL de soquetes do windows copia uma descrição de soquetes implementação do windows, incluindo a identificação do fornecedor.  O texto \(até 256 caracteres de comprimento\) pode conter todos os caracteres, mas fornecedores for avisado para incluir caracteres de controle e de formatação: o uso mais provável que um aplicativo colocará neste a exibição é truncado possivelmente \(\) em uma mensagem de status.  
  
 *szSystemStatus*  
 Uma cadeia de caracteres terminada por caractere ASCII em que o DLL de soquetes do windows copia informações pertinentes de status ou de configuração.  A DLL de soquetes do windows deve usar este campo somente se informações podem ser úteis para o usuário ou a equipe de suporte; não deve ser considerada como uma extensão do campo de **szDescription** .  
  
 *iMaxSockets*  
 O número máximo de soquetes que um único processo pode potencialmente aberto.  Uma implementação de soquetes do windows pode fornecer um pool global de soquetes para alocação para qualquer processo; como alternativa, é possível alocar recursos do processo para soquetes.  O número bem pode refletir a maneira em que o DLL de soquetes do windows ou o software de rede foram configurados.  Autores de aplicativos podem usar esse número como um valor que indica se bruta da implementação de soquetes do windows é útil pelo aplicativo.  Por exemplo, um servidor do windows X pode verificar **iMaxSockets** quando iniciado primeiro: se for menor que 8, o aplicativo exibiria uma mensagem de erro que instrui o usuário para reconfigurar o software de rede. \(Essa é uma situação em que o texto de **szSystemStatus** pode ser usado.\) Obviamente não há nenhuma garantia de que um aplicativo específico pode realmente atribuir soquetes de **iMaxSockets** , pois pode haver outros aplicativos de soquetes do windows em uso.  
  
 *iMaxUdpDg*  
 O tamanho em bytes de datagrama a maior \(UDP\) de protocolo UDP que pode ser enviada ou recebido por um aplicativo de soquetes do windows.  Se a implementação não impõe nenhum limite, **iMaxUdpDg** é zero.  Em muitas implementações de soquetes de Berkeley, há um limite implícito de 8192 bytes nas datagramas UDP \(que estão fragmentadas se necessário\).  Uma implementação de soquetes do windows pode impor um limite baseado, por exemplo, a alocação de buffers de reassembly do fragmento.  O valor mínimo de **iMaxUdpDg** para uma implementação de correspondência de soquetes do windows é 512.  Observe que independentemente do valor de **iMaxUdpDg**, ele é desaconselhável para tentar enviar uma datagrama extensivos que seja maior que o protocolo Maximum Unit \(MTU\) da rede. Soquetes \(API do windows não fornece um mecanismo para descobrir o MTU, mas não deverá haver menos de 512 bytes.\)  
  
 *lpVendorInfo*  
 Um ponteiro muito a uma estrutura de dados fornecedor\- específica.  A definição dessa estrutura \(se\) fornecido está além do escopo da especificação de soquetes do windows.  
  
> [!NOTE]
>  MFC no, a estrutura de `WSADATA` é retornada pela função de `AfxSocketInit` , que chama na função de `InitInstance` .  Você pode recuperar a estrutura e armazená\-las em seu programa se você precisar usar posteriormente informações delas.  
  
## Requisitos  
 **Cabeçalho:** winsock2.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxSocketInit](../Topic/AfxSocketInit.md)