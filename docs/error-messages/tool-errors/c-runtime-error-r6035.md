---
title: R6035 de erro de tempo de execução C | Microsoft Docs
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
ms.openlocfilehash: ecadf1793475e1cf5f354796c71a1894884e24e9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299741"
---
# <a name="c-runtime-error-r6035"></a>R6035 de erro de tempo de execução do C
Microsoft Visual C++ Runtime Library, erro R6035 - um módulo neste aplicativo está inicializando o cookie de segurança global do módulo, enquanto uma função depender esse cookie de segurança está ativa.  Chamada security_init_cookie anteriormente.  
  
 [security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes do primeiro uso do cookie de segurança global.  
  
 O cookie de segurança global é usado para proteção de saturação de buffer no código compilado com [/GS (verificação de segurança do Buffer)](../../build/reference/gs-buffer-security-check.md) e no código que usa tratamento estruturado de exceções. Essencialmente, na entrada para uma função de saturação protegido, o cookie é colocado na pilha e na saída, o valor na pilha é comparado com o cookie global. Nenhuma diferença entre eles indica que uma saturação de buffer ocorreu e resulta em um encerramento imediato do programa.  
  
 Erro R6035 indica que uma chamada para `__security_init_cookie` foi feita depois que uma função protegida foi inserida. Se continuar a execução, uma saturação de buffer artificiais seria detectada porque o cookie na pilha não corresponderia o cookie global.  
  
 Considere o seguinte exemplo DLL. O ponto de entrada DLL é definido para DllEntryPoint por meio do vinculador [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) opção. Isso ignora a inicialização do CRT que normalmente seria inicializar o cookie de segurança global, para que a DLL em si deve chamar `__security_init_cookie`.  
  
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
  
 Este exemplo gerará o erro R6035 porque DllEntryPoint usa tratamento estruturado de exceções e, portanto, o cookie de segurança para detectar saturações de buffer. Quando o que dllinitialize é chamado, o cookie de segurança global já foi colocado na pilha.  
  
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
  
 Nesse caso, DllEntryPoint não está protegido contra saturações de buffer (ele tem nenhum buffer de cadeia de caracteres de local e não usa o tratamento de exceção estruturada); Portanto, ele pode chamar com segurança `__security_init_cookie`. Depois, ele chama uma função auxiliar que está protegida.  
  
> [!NOTE]
>  Mensagem de erro é R6035 somente gerado pelo x86 de depuração CRT e apenas para tratamento estruturado de exceções, mas a condição é um em todas as plataformas e para todos os formulários de exceção de tratamento de erros, como C++ EH.  
  
## <a name="see-also"></a>Consulte também  
 [Análise aprofundada das verificações de segurança do compilador](http://go.microsoft.com/fwlink/p/?linkid=7260)