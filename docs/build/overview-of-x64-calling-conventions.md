---
title: "Vis&#227;o geral de conven&#231;&#245;es de chamada de x64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: a05db5eb-0844-4d9d-8b92-b1b2434be0ea
caps.latest.revision: 12
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vis&#227;o geral de conven&#231;&#245;es de chamada de x64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Duas alterações importantes de x86 a [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] é o recurso de 64 bits addressing e um conjunto de plano de 16 registros de 64 bits para uso geral.  Dado o conjunto expandido do registro, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] usa apenas [\_\_fastcall](../cpp/fastcall.md) que chama a convenção e um modelo RISC\- base de manipulação de exceção.  O modelo de `__fastcall` usa registros para que os primeiros quatro argumentos e o quadro de pilha passa os outros parâmetros.  
  
 As seguintes ajuda a opção de compilador você otimiza o aplicativo para [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]:  
  
-   [\/favor \(Otimizar para especificações da arquitetura\)](../build/reference/favor-optimize-for-architecture-specifics.md)  
  
## Convenção de chamada  
 A interface de binária de aplicativo \(ABI\) de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] é uma convenção de chamada de rápido\- chamada de 4 registros, com pilha suporte para esses registros.  Há uma correspondência um\-para\-um entre argumentos strict em uma função, e os registros para esses argumentos.  Nenhum argumento que não couber em 8 bytes, ou não é 1, 2, 4, ou 8 bytes, devem ser passados por referência.  Não há nenhuma tentativa de espalhar um único argumento por vários registros.  A pilha de registro x87 não é usado.  Pode ser usada, mas deve ser considerada volátil através de chamadas de função.  Todas as operações de ponto flutuante são feitas usando os registros de 16 MMX.  Os argumentos são passados em registros RCX, RDX, R8, e R9.  Se os argumentos são flutuante\/double, eles são passados em XMM0L, em XMM1L, em XMM2L, e em XMM3L.  argumentos de 16 bytes são passados por referência.  Passagem de parâmetro é descrito em detalhes em [Passagem de parâmetro](../build/parameter-passing.md).  Além desses registros, RAX, R10, R11, XMM4, e XMM5 são voláteis.  Todos outros registros são permanentes.  O uso do registro está documentado em detalhes em [Uso do Registro](../build/register-usage.md) e em [Registros salvos de chamador\/receptor](../build/caller-callee-saved-registers.md).  
  
 O chamador é responsável para atribuir espaço para parâmetros para o receptor, e sempre deve atribuir espaço suficiente para os parâmetros 4 do registro, mesmo se o receptor não tem que vários parâmetros.  Isso ajuda na simplicidade de suporte C unprototyped funções, e o vararg C\/C\+\+ funciona.  Para o vararg ou funções unprototyped, todos os valores de flutuante devem ser duplicados no registro de uso geral correspondente.  Todos os parâmetros anteriores dos primeiros 4 devem ser armazenados na pilha, acima de armazenamento reverso para os primeiros 4, antes da chamada.  Os detalhes de função de Vararg podem ser encontrados em [Varargs](../build/varargs.md).  Informações de função de Unprototyped é detalhada em [Funções sem protótipo](../build/unprototyped-functions.md).  
  
## Alinhamento  
 A maioria das estruturas são alinhadas ao alinhamento natural.  As exceções são principais o ponteiro de pilha e memória de malloc ou de alloca, que são alinhadas ao byte 16, para ajudar o desempenho.  O alinhamento acima de 16 bytes deve ser feito manualmente, mas como 16 bytes são um tamanho comuns de alinhamento para operações de MMX, isso deve bastar para a maioria de código.  Para obter mais informações sobre o layout e o alinhamento de estrutura consulte [Tipos e armazenamento](../build/types-and-storage.md).  Para obter informações sobre o layout da pilha, consulte [Uso da pilha](../build/stack-usage.md).  
  
## Incapacidade de enrolar  
 Todas as funções de folha \[as funções que nem chamam uma função, ou atribuem todo o espaço de pilha elas mesmas\] devem ser anotadas com os dados \[chamados de xdata ou ehdata, que são apontados de pdata\] que descreve o sistema operacional como os desenrolar corretamente, para recuperar registros permanentes.  Os prólogos e os epílogos são altamente restritos, de modo que eles possam ser corretamente descritos em xdata.  O ponteiro de pilha deve ser alinhado a 16 bytes, exceto as funções de folha, em toda a região de código que não é parte de um epílogo ou um prólogo.  Para obter detalhes sobre a estrutura apropriada de prólogo e de epílogos de função, consulte [Prólogo e epílogo](../build/prolog-and-epilog.md).  Para obter mais informações sobre manipulação de exceção e manipulação de exceções\/de pdata e de xdata de desenrolamento consulte [Tratamento de exceções \(x64\)](../build/exception-handling-x64.md).  
  
## Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)