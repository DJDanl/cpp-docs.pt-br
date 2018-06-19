---
title: Usando VERIFY em vez de ASSERT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 712c22bec1d6ce2d67208de9a139dff7621ad4cd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376553"
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
  
-   `strcpy_s( )` cópias "`Hello, World`" em uma parte aleatória de memória, possivelmente, travando o aplicativo ou fazendo com que o sistema parar de responder, ou  
  
-   `free()` tentativas liberar a memória que nunca foi alocada.  
  
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