---
title: "Seguran&#231;a de threads na Biblioteca Padr&#227;o C++ | Microsoft Docs"
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
helpviewer_keywords: 
  - "Biblioteca Padrão C++, segurança de threads"
  - "segurança de threads"
  - "segurança de threads, Biblioteca de Modelos Padrão"
ms.assetid: 9351c8fb-4539-4728-b0e9-226e2ac4284b
caps.latest.revision: 21
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Seguran&#231;a de threads na Biblioteca Padr&#227;o C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As regras para acesso thread\-safe a seguir se aplicam a todas as classes na Biblioteca Padrão C\+\+. Isso inclui `shared_ptr`, como descrito a seguir.  Às vezes, são dadas garantias maiores, por exemplo, os objetos iostream padrão, como descrito a seguir, e os tipos projetados especificamente para multithreading, como os em [\<atomic\>](../standard-library/atomic.md).  
  
 Um objeto é thread\-safe para leitura de vários threads.  Por exemplo, dado um objeto A, é seguro ler A do thread 1 e do thread 2 simultaneamente.  
  
 Se um objeto estiver sendo gravado por um thread, todas as leituras e as gravações nesse objeto no mesmo thread ou em outros deverão ser protegidas.  Por exemplo, dado um objeto A, se o thread 1 estiver sendo gravado em A, o thread 2 deverá ser impedido de ler de ou gravar em A.  
  
 É seguro ler e gravar em uma instância de um tipo, mesmo que outro thread esteja lendo ou gravando em uma instância diferente do mesmo tipo.  Por exemplo, dados os objetos A e B do mesmo tipo, é seguro quando A está sendo gravado no thread 1 e B está sendo gravado no thread 2.  
  
## shared\_ptr  
 Vários threads podem ler e gravar simultaneamente objetos [shared\_ptr](../standard-library/shared-ptr-class.md) diferentes, mesmo quando os objetos são cópias que compartilham a propriedade.  
  
## iostream  
 Os objetos iostream padrão `cin`, `cout`, `cerr`, `clog`, `wcin`, `wcout`, `wcerr` e `wclog` seguem as mesmas regras das outras classes, com esta exceção: é seguro gravar em um objeto de vários threads.  Por exemplo, o thread 1 pode gravar em [cout](../Topic/cout.md) ao mesmo tempo em que o thread 2.  Porém, isso pode misturar a saída dos dois threads.  
  
> [!NOTE]
>  A leitura de um buffer de stream não é considerada uma operação segura.  Em vez disso, ela é considerada um operação de gravação, porque o estado da classe muda.  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)