---
title: "Estrutura DEVNAMES | Microsoft Docs"
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
  - "DEVNAMES"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DEVNAMES"
ms.assetid: aac97f60-2169-471a-ba5d-c0baed9eed9a
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura DEVNAMES
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `DEVNAMES` contém as cadeias de caracteres que identificam o driver, o dispositivo, e os nomes de porta por saída para uma impressora.  
  
## Sintaxe  
  
```  
  
      typedef struct tagDEVNAMES { /* dvnm */  
    WORD wDriverOffset;  
    WORD wDeviceOffset;  
    WORD wOutputOffset;  
    WORD wDefault;  
    /* driver, device, and port-name strings follow wDefault */  
} DEVNAMES;  
```  
  
#### Parâmetros  
 *wDriverOffset*  
 Entrada\/saída \(\) especifica o deslocamento em caracteres em uma cadeia de caracteres com terminação nula que contém o nome do arquivo \(sem a extensão\) de driver de dispositivo.  Na entrada, essa cadeia de caracteres é usada para determinar a impressora exibir inicialmente na caixa de diálogo.  
  
 *wDeviceOffset*  
 Entrada\/saída \(\) especifica o deslocamento em caracteres para a cadeia de caracteres com terminação nula \(máximo de 32 bytes que incluem null\) que contém o nome do dispositivo.  Essa cadeia de caracteres deve ser idêntica ao membro de **dmDeviceName** da estrutura de [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) .  
  
 *wOutputOffset*  
 Entrada\/saída \(\) especifica o deslocamento em caracteres para a cadeia de caracteres com terminação nula que contém o nome do dispositivo físico de OS para o meio de saída \(porta de saída\).  
  
 *wDefault*  
 Especifica se as cadeias de caracteres contidas na estrutura de `DEVNAMES` identificam a padrão.  Essa cadeia de caracteres é usada para verificar se a padrão não tenha sido alterada desde que a operação da última cópia.  Na entrada, se o sinalizador de **DN\_DEFAULTPRN** for definido, os outros valores na estrutura de `DEVNAMES` são verificados na impressora padrão atual.  Se qualquer uma das cadeias de caracteres não correspondem, será exibida uma mensagem de aviso informando o usuário que o documento pode precisar ser reformatado.  Na saída, o membro de **wDefault** é alterado se a caixa de diálogo de configuração de cópia foi exibida e o usuário optou o botão OK.  O sinalizador de **DN\_DEFAULTPRN** é definido como se a padrão tiver sido selecionada.  Se uma impressora específica for selecionada, o sinalizador não será definido.  Todos bit restantes deste membro são reservados para uso interno pelo procedimento da caixa de diálogo de impressão.  
  
## Comentários  
 A função de **PrintDlg** usa essas cadeias de caracteres para inicializar membros na caixa de diálogo definida pelo sistema de cópia.  Quando o usuário fecha a caixa de diálogo, as informações sobre a impressora selecionada será retornada nessa estrutura.  
  
## Requisitos  
 **Header:** commdlg.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CPrintDialog::CreatePrinterDC](../Topic/CPrintDialog::CreatePrinterDC.md)