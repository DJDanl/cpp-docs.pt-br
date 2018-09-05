---
title: Erro de tempo de execução em C R6035 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6035
dev_langs:
- C++
helpviewer_keywords:
- R6035
ms.assetid: f8fb50b8-18bf-4258-b96a-b0a9de468d16
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: aa300619d59bdcf4295c8db9f8e9ebf1acb6bb3a
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43683584"
---
# <a name="c-runtime-error-r6035"></a>Erro de tempo de execução em C R6035
Microsoft Visual C++ Runtime Library, erro R6035 - um módulo neste aplicativo está inicializando o cookie de segurança global do módulo, enquanto uma função de terceira parte confiável no cookie de segurança que está ativa.  Chamada security_init_cookie anteriormente.  
  
 [security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes do primeiro uso do cookie de segurança global.  
  
 O cookie de segurança global é usado para proteção de estouro de buffer no código compilado com [/GS (Buffer Security Check)](../../build/reference/gs-buffer-security-check.md) e no código que usa o tratamento de exceções estruturado. Essencialmente, na entrada para uma função protegida contra estouro, o cookie é colocado na pilha e na saída, o valor na pilha é comparado com o cookie global. Qualquer diferença entre eles indica que um estouro de buffer tiver ocorrido e resulta em um encerramento imediato do programa.  
  
 Erro em R6035 indica que uma chamada para `__security_init_cookie` foi feita depois que uma função protegida foi inserida. Se a execução continue, um estouro de buffer artificiais seria detectado porque o cookie na pilha não corresponderia o cookie global.  
  
 Considere o seguinte exemplo DLL. O ponto de entrada DLL é definido para DllEntryPoint por meio de vinculador [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) opção. Isso ignora a inicialização do CRT que normalmente seria inicializar o cookie de segurança global, portanto, a própria DLL deve chamar `__security_init_cookie`.  
  
```  
// Wrong way to call __security_init_cookie  
DllEntryPoint(...) {  
   DllInitialize();  
   ...  
   __try {  
      ...  
   } __except()... {  
      ...  
   }  
}  
  
void DllInitialize() {  
   __security_init_cookie();  
}  
```  
  
 Este exemplo irá gerar o erro R6035 porque DllEntryPoint usa o tratamento de exceções estruturado e, portanto, usa o cookie de segurança para detectar saturações de buffer. No momento que dllinitialize é chamado, o cookie de segurança global já foi colocado na pilha.  
  
 A maneira correta é demonstrada neste exemplo:  
  
```  
// Correct way to call __security_init_cookie  
DllEntryPoint(...) {  
   __security_init_cookie();  
   DllEntryHelper();  
}  
  
void DllEntryHelper() {  
   ...  
   __try {  
      ...  
   } __except()... {  
      ...  
   }  
}  
```  
  
 Nesse caso, DllEntryPoint não está protegido contra estouros de buffer (ele tem buffers nenhuma cadeia de caracteres local e não usar o tratamento de exceções estruturado); Portanto, ele pode chamar com segurança `__security_init_cookie`. Em seguida, ele chama uma função auxiliar que é protegida.  
  
> [!NOTE]
>  Mensagem de erro é R6035 somente gerados por x86 de depuração CRT e apenas para tratamento de exceções estruturado, mas a condição é um erro em todas as plataformas e para todos os formulários de exceção tratamento, como C++ EH.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos de segurança no MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/06/28/security-features-in-microsoft-visual-c/)