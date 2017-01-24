---
title: "&lt; codecvt &gt; | Microsoft Docs"
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
  - "codecvt"
  - "std::<codecvt>"
  - "std.<codecvt>"
  - "<codecvt>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho codecvt"
ms.assetid: d44ee229-00d5-4761-9b48-0c702122789d
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; codecvt &gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define várias classes de modelo que descreve os objetos com base na classe de modelo [codecvt](../standard-library/codecvt-class.md). Esses objetos podem servir como [facetas de localidade](../standard-library/locale-class.md#facet_class) que controlam conversões entre uma sequência de valores do tipo `Elem` e uma sequência de valores do tipo `char`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <codecvt>  
  
```  
  
## <a name="remarks"></a>Comentários  
 As facetas de localidade declaradas nesse cabeçalho converter entre várias codificações de caracteres. Para caracteres largos (armazenados dentro do programa em inteiros de tamanho fixo):  
  
-   UCS-4 é Unicode (ISO 10646) codificado dentro do programa  
  
-   UCS-4 é Unicode (ISO 10646) codificado dentro do programa como um inteiro de 32 bits.  
  
-   UCS-2 é Unicode codificado dentro do programa  
  
-   UCS-2 é Unicode codificado no programa como um inteiro de 16 bits.  
  
-   UTF-16 é codificado dentro do programa como um Unicode  
  
-   UTF-16 é Unicode codificado no programa como um ou dois inteiros de 16 bits. (Observe que isso não atender aos requisitos de uma codificação de caractere largo válida para o padrão C ou C++ padrão. No entanto é amplamente usado dessa forma.)  
  
 Para fluxos de bytes (armazenadas em um arquivo, transmitido como uma sequência de bytes ou armazenado dentro do programa em uma matriz de `char`):  
  
-   UTF-8 é a codificação Unicode  
  
-   UTF-8 é Unicode codificado em um fluxo de bytes como um ou mais bytes de 8 bits com uma ordem de byte determinística.  
  
-   UTF-16LE está codificado em Unicode  
  
-   UTF-16LE é Unicode codificado em um fluxo de bytes como UTF-16 com cada inteiro de 16 bits primeiro apresentado como dois bytes de oito bits menos significativos bytes.  
  
-   UTF-16BE está codificado em Unicode  
  
-   UTF-16BE é Unicode codificado em um fluxo de bytes como UTF-16 com cada inteiro de 16 bits apresentado como dois bytes de oito bits, o byte mais significativo primeiro.  
  
### <a name="enumerations"></a>Enumerações  
  
|||  
|-|-|  
|[codecvt_mode](../Topic/%3Ccodecvt%3E%20enums.md#codecvt_mode_enumeration)|Especifica as informações de configuração de facetas de localidade.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[codecvt_utf8](../Topic/%3Ccodecvt%3E%20functions.md#codecvt_utf8)|Representa uma faceta de localidade que converte entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-8.|  
|[codecvt_utf8_utf16](%3Ccodecvt%3E%20functions.md#codecvt_utf8_utf16)|Representa uma faceta de localidade que converte entre caracteres largos codificados como UTF-16 e um fluxo de bytes codificado como UTF-8.|  
|[codecvt_utf16](../Topic/%3Ccodecvt%3E%20functions.md#codecvt_utf16)|Representa uma faceta de localidade que converte entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE ou UTF-16BE.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< codecvt>  
  
 **Namespace:** stdt  
  
## <a name="see-also"></a>Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)




