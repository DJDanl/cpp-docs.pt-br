---
title: "Acionando exceções de Software | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- run-time errors, treating as exceptions
- exception handling [C++], errors as exceptions
- exceptions [C++], flagging errors as exceptions
- errors [C++], treating as exceptions
- exception handling [C++], detecting errors
- structured exception handling [C++], errors as exceptions
- exceptions [C++], software
- RaiseException function
- software exceptions [C++]
- formats [C++], exception codes
ms.assetid: be1376c3-c46a-4f52-ad1d-c2362840746a
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 333db5bf60d8b542a69efb3dba9d39c624e8b605
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="raising-software-exceptions"></a>Acionando exceções de software
Algumas das origens mais comuns de erros do programa não são sinalizadas como exceções pelo sistema. Por exemplo, se você tenta alocar um bloco de memória, mas não há memória suficiente, o tempo de execução ou a função de API não geram uma exceção, mas retornam um código de erro.  
  
 No entanto, você pode tratar qualquer condição como uma exceção ao detectar essa condição em seu código e relatá-las, em seguida, chamando o [RaiseException](http://msdn.microsoft.com/library/windows/desktop/ms680552) função. Ao sinalizar erros dessa maneira, você aproveitas as vantagens de manipulação de exceções estruturada em qualquer tipo de erro de tempo de execução.  
  
 Para usar a manipulação de exceção estruturada com erros:  
  
-   Defina seu próprio código de exceção para o evento.  
  
-   Chamar **RaiseException** quando você detectar um problema.  
  
-   Use filtros de manipulação de exceções para testar o código de exceção definido.  
  
 O arquivo de WINERROR.H mostra o formato dos códigos de exceção. Para verificar se você não definiu um código em conflito com um código de exceção existente, defina o terceiro bit mais significativo como 1. Os quatro bit mais significativos devem ser definidos como mostrado na tabela a seguir.  
  
|Bits|Configuração binária recomendada|Descrição|  
|----------|--------------------------------|-----------------|  
|31-30|11|Esses dois bits descrevem o status básico de código:  11 = erro, 00 = êxito, 01 = informativo, 10 = aviso.|  
|29|1|Bit cliente. Definido como 1 para códigos definidos pelo usuário.|  
|28|0|Bit reservado. (Deixe definido como 0.)|  
  
 Você pode definir os dois primeiros bits com uma configuração diferente do 11 binário se você desejar, embora a configuração de “erro” seja apropriada para a maioria das exceções. É importante lembrar de definir os bits 29 e 28 conforme mostrado na tabela anterior.  
  
 O código de erro resultante, portanto, deve ter os quatro bits mais altos definido como e hexadecimal. Por exemplo, as seguintes definições definem códigos de exceção que não estão em conflito com qualquer códigos de exceção do Windows. (No entanto, talvez seja necessário verificar se os códigos são usados por DLL de terceiros.)  
  
```  
#define STATUS_INSUFFICIENT_MEM       0xE0000001  
#define STATUS_FILE_BAD_FORMAT        0xE0000002  
```  
  
 Depois que você tiver definido um código de exceção, poderá usá-lo para gerar uma exceção. Por exemplo, o seguinte código gera a exceção STATUS_INSUFFICIENT_MEM em resposta a um problema de alocação de memória:  
  
```  
lpstr = _malloc( nBufferSize );  
if (lpstr == NULL)  
    RaiseException( STATUS_INSUFFICIENT_MEM, 0, 0, 0);  
```  
  
 Se você quiser simplesmente gerar uma exceção, pode definir os últimos três parâmetros como 0. Os últimos três parâmetros são úteis para passar informações adicionais e definir um sinalizador que impeça manipuladores de continuarem a execução. Consulte o [RaiseException](http://msdn.microsoft.com/library/windows/desktop/ms680552) funcionar a [!INCLUDE[winsdkshort](../atl-mfc-shared/reference/includes/winsdkshort_md.md)] para obter mais informações.  
  
 Em seus filtros de manipulação de exceções, você pode testar os códigos que você definiu. Por exemplo:  
  
```  
__try {  
    ...  
}  
__except (GetExceptionCode() == STATUS_INSUFFICIENT_MEM ||  
        GetExceptionCode() == STATUS_FILE_BAD_FORMAT )  
```  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
