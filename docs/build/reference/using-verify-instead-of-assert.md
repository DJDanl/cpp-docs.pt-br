---
title: Usando VERIFY em vez de ASSERT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- assert
dev_langs:
- C++
helpviewer_keywords:
- ASSERT statements
- debugging [MFC], ASSERT statements
- VERIFY macro
- assertions, troubleshooting ASSERT statements
- debugging assertions
- assertions, debugging
ms.assetid: 4c46397b-3fb1-49c1-a09b-41a72fae3797
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4ffe046a281bbbbefc251b48df55ecd275515e60
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-verify-instead-of-assert"></a>Usando VERIFY em vez de ASSERT
Suponha que, quando você executa a versão de depuração do seu aplicativo MFC, não há nenhum problema. No entanto, a versão de lançamento do mesmo aplicativo falha, retorna resultados incorretos e/ou exibe alguns outros comportamento anormal.  
  
 Esse problema pode ser causado quando você coloca código importantes em uma instrução ASSERT para verificar que ele seja executado corretamente. Porque as instruções de declaração são comentadas em uma compilação de versão de um programa MFC, o código não é executado em uma compilação de versão.  
  
 Se você estiver usando ASSERT para confirmar se uma chamada de função foi bem-sucedida, considere o uso de [verificar](../../mfc/reference/diagnostic-services.md#verify) em vez disso. A macro VERIFY avalia seus próprios argumentos em ambos os depuração e compilações de versão do aplicativo.  
  
 Outra preferência técnica é atribuir o valor de retorno da função em uma variável temporária e, em seguida, teste a variável em uma instrução ASSERT.  
  
 Examine o fragmento de código a seguir:  
  
```  
enum {  
    sizeOfBuffer = 20  
};  
char *buf;  
ASSERT(buf = (char *) calloc(sizeOfBuffer, sizeof(char) ));  
strcpy_s( buf, sizeOfBuffer, "Hello, World" );  
free( buf );  
```  
  
 Esse código é executado perfeitamente em uma versão de depuração de um aplicativo do MFC. Se a chamada para `calloc( )` falhar, uma mensagem de diagnóstico que inclui o arquivo e número de linha aparece. No entanto, em uma versão comercial de um aplicativo MFC:  
  
-   a chamada para `calloc( )` nunca ocorrer, deixando `buf` não inicializado, ou  
  
-   `strcpy_s( )`cópias "`Hello, World`" em uma parte aleatória de memória, possivelmente, travando o aplicativo ou fazendo com que o sistema parar de responder, ou  
  
-   `free()`tentativas liberar a memória que nunca foi alocada.  
  
 Para usar ASSERT corretamente, o exemplo de código deve ser alterado para o seguinte:  
  
```  
enum {  
    sizeOfBuffer = 20  
};  
char *buf;  
buf = (char *) calloc(sizeOfBuffer, sizeof(char) );  
ASSERT( buf != NULL );  
strcpy_s( buf, sizeOfBuffer, "Hello, World" );  
free( buf );  
```  
  
 Ou, você pode usar em vez disso, verifique se:  
  
```  
enum {  
    sizeOfBuffer = 20  
};  
char *buf;  
VERIFY(buf = (char *) calloc(sizeOfBuffer, sizeof(char) ));  
strcpy_s( buf, sizeOfBuffer, "Hello, World" );  
free( buf );  
```  
  
## <a name="see-also"></a>Consulte também  
 [Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)