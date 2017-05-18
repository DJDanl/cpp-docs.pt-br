---
title: "Compilador aviso (nível 1) C4772 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4772
dev_langs:
- C++
helpviewer_keywords:
- C4772
ms.assetid: dafe6fd8-9faf-41f5-9d66-a55838742c14
caps.latest.revision: 10
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 41d26a5ecf3dd44256f1673dfaf47948103f41d3
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4772"></a>Compilador C4772 de aviso (nível 1)
\#importação referenciou um tipo de uma biblioteca de tipos ausente; 'missing_type' usado como um espaço reservado  
  
 Uma biblioteca de tipos foi referenciada com o [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva. No entanto, a biblioteca de tipos continha uma referência a outra biblioteca de tipos que não foi referenciada com `#import`. Esse outro arquivo. tlb não foi encontrado pelo compilador.  
  
 Observe que o compilador não localizará bibliotecas de tipo em diretórios diferentes se você usar o [/I (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md) opção de compilador para especificar esses diretórios. Se você deseja que o compilador encontrar bibliotecas de tipo em diretórios diferentes, adicione esses diretórios à variável de ambiente PATH.  
  
 Esse aviso é, por padrão, emitido como um erro. C4772 não pode ser suprimido com /W0.  
  
## <a name="example"></a>Exemplo  
 Essa é a primeira biblioteca de tipo necessária para reproduzir C4772.  
  
```  
// c4772a.idl  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12b")]  
library C4772aLib  
{  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c100")]  
   enum E_C4772a  
   {  
      one, two, three  
   };  
};  
```  
  
## <a name="example"></a>Exemplo  
 Essa é a biblioteca de tipo segundo necessária para reproduzir C4772.  
  
```  
// c4772b.idl  
// post-build command: del /f C4772a.tlb  
// C4772a.tlb is available when c4772b.tlb is built  
[uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12d")]  
library C4772bLib  
{  
   importlib ("c4772a.tlb");  
   [uuid("f87070ba-c6d9-405c-a8e4-8cd9ca25c12e")]  
   struct S_C4772b  
   {  
      enum E_C4772a e;  
   };  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4772:  
  
```  
// C4772.cpp  
// assumes that C4772a.tlb is not available to the compiler  
// #import "C4772a.tlb"  
#import "C4772b.tlb"   // C4772 uncomment previous line to resolve  
                       // and make sure c4772a.tlb is on disk  
```
