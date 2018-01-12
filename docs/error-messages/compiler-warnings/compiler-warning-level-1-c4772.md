---
title: "Compilador (nível 1) de aviso C4772 | Microsoft Docs"
ms.date: 11/04/2016
ms.technology: cpp-tools
ms.topic: error-reference
f1_keywords: C4772
dev_langs: C++
helpviewer_keywords: C4772
ms.assetid: dafe6fd8-9faf-41f5-9d66-a55838742c14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 631cd4f872c7b8912b791417c04f6c6e9e056bdd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4772"></a>Compilador C4772 de aviso (nível 1)

> \#import referenciou um tipo de uma biblioteca de tipos faltando; '*tipo ausente*' usado como um espaço reservado

Uma biblioteca de tipo referenciada com o [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva. No entanto, a biblioteca de tipos continha uma referência a outra biblioteca de tipos que não foi referenciada com `#import`. Esse outro arquivo. tlb não foi encontrado pelo compilador.

Observe que o compilador não localizará bibliotecas de tipo em diretórios diferentes se você usar o [/I (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md) opção de compilador para especificar os diretórios. Se você deseja que o compilador para encontrar as bibliotecas de tipo em diretórios diferentes, adicione esses diretórios à variável de ambiente PATH.

Por padrão, esse aviso é emitido como um erro. C4772 não pode ser suprimido com /W0.

## <a name="example"></a>Exemplo

Esta é a primeira biblioteca de tipo necessária para reproduzir C4772.

```IDL
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

Esta é a segunda biblioteca de tipo necessária para reproduzir C4772.

```IDL
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

O exemplo a seguir gera C4772:

```cpp
// C4772.cpp
// assumes that C4772a.tlb is not available to the compiler
// #import "C4772a.tlb"
#import "C4772b.tlb"   // C4772 uncomment previous line to resolve
                       // and make sure c4772a.tlb is on disk
```