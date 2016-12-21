---
title: "R6035 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "R6035"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6035"
ms.assetid: f8fb50b8-18bf-4258-b96a-b0a9de468d16
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6035 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Biblioteca de tempo de execução Microsoft Visual C\+\+, erro R6035 \- um módulo neste aplicativo está inicializando o cookie global de segurança do módulo quando uma função que confia nessa cookie de segurança está ativa.  Chame o \_\_security\_init\_cookie anterior.  
  
 [\_\_security\_init\_cookie](../../c-runtime-library/reference/security-init-cookie.md) deve ser chamado antes do primeiro uso do cookie global de segurança.  
  
 O cookie global de segurança é usada para proteção de excesso de buffer em código compilado com [\/GS \(verificação de segurança do buffer\)](../Topic/-GS%20\(Buffer%20Security%20Check\).md) e no código que usa a manipulação de exceção estruturados.  Essencialmente, na entrada para uma função excedente\- sombreada, o cookie é colocada na pilha, e na saída, o valor na pilha é comparado com o cookie global.  Qualquer diferença entre eles indica que uma excesso de buffer ocorreu e resulta na terminação imediata de programa.  
  
 O erro R6035 indica que uma chamada a `__security_init_cookie` esteve feito depois que uma função protegida foi inserida.  Se a execução for continuar, uma especulativo excesso de buffer será detectada porque o cookie na pilha não corresponderá ao cookie global.  
  
 Considere o exemplo da DLL.  O ponto de entrada da DLL é definido como DllEntryPoint com a opção de [\/ENTRY \(símbolo do ponto de entrada\)](../../build/reference/entry-entry-point-symbol.md) do vinculador.  Ele ignora a inicialização de CRT que inicializaria normalmente o cookie global de segurança, assim que o DLL próprio deve chamar `__security_init_cookie`.  
  
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
  
 Este exemplo gerará o erro R6035 porque DllEntryPoint usa a manipulação de exceção estruturados e usa como consequência o cookie de segurança para detectar que haja excesso de buffer.  Antes de DllInitialize é chamado, o cookie global de segurança tiver sido colocada na pilha.  
  
 A forma correta é demonstrada neste exemplo:  
  
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
  
 Nesse caso, DllEntryPoint não é protegido em excesso de buffer \(não tem nenhum buffer local da cadeia de caracteres e não usa a manipulação de exceção estruturado\); em virtude disso pode chamar com segurança `__security_init_cookie`.  Chama uma função auxiliar que é protegida.  
  
> [!NOTE]
>  A mensagem de erro R6035 é gerado somente por CRT de depuração x86, e apenas para a manipulação de exceção estruturados, mas a condição é um erro em todas as plataformas, e para todos os formatos de manipulação de exceções, como C\+\+ EH.  
  
## Consulte também  
 [Verificações de segurança do compilador detalhados](http://go.microsoft.com/fwlink/?linkid=7260)