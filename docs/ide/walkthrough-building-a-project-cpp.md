---
title: "Instru&#231;&#245;es passo a passo: compilando um projeto (C++) | Microsoft Docs"
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
  - "compilando projetos [C++]"
  - "projetos [C++], criando"
  - "compilação de projetos [C++]"
ms.assetid: d459bc03-88ef-48d0-9f9a-82d17f0b6a4d
caps.latest.revision: 14
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: compilando um projeto (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Nesse passo a passo, você introduz intencionalmente um erro de sintaxe do Visual C\+\+ em seu código para saber como é um erro de compilação e como o corrigir.  Ao compilar o projeto, uma mensagem de erro indica o tipo de problema e o local onde o mesmo ocorreu.  
  
## Pré-requisitos  
  
-   Esta explicação passo a passo pressupõe que você compreenda os fundamentos da linguagem C\+\+.  
  
-   Também pressupõe que você tenha concluído os passo a passo relacionados anteriormente, que estão listados em [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
### Para corrigir erros de compilação  
  
1.  Em TestGames.cpp, exclua o ponto e vírgula na última linha para que fique semelhante a esta:  
  
     `return 0`  
  
2.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
3.  Uma mensagem na janela **Lista de Erros** indica que ocorreu um erro na compilação do projeto.  A descrição parece com esta::  
  
     `error C2143: syntax error : missing ';' before '}'`  
  
     Para exibir informações de ajuda sobre este erro, realce\-o na janela **Lista de erros** e, em seguida, use a tecla F1.  
  
4.  Adicione o ponto e vírgula novamente no fim da linha que tem o erro de sintaxe:  
  
     `return 0;`  
  
5.  Na barra de menus, escolha **Compilar**, **Compilar Solução**.  
  
     Uma mensagem na janela **Saída** indica que o projeto foi compilado com êxito.  
  
  **1\>\-\-\-\-\-\- Compilação iniciada: Projeto: Game, Configuração: Debug Win32 \-\-\-\-\-\-**  
**1\> TestGames.cpp**  
**1\>  Game.vcxproj \-\> C:\\Users\\\<username\>\\Documents\\Visual Studio *\<version\>*\\Projects\\Game\\Debug\\Game.exe**  
**\=\=\=\=\=\=\=\=\=\= Compilação: 1 com êxito, 0 com falha, 0 atualizada, 0 ignorada \=\=\=\=\=\=\=\=\=\=**  
  
## Próximas etapas  
 **Anterior:** [Instruções passo a passo: trabalhando com projetos e soluções \(C\+\+\)](../Topic/Walkthrough:%20Working%20with%20Projects%20and%20Solutions%20\(C++\).md) &#124; **Próxima:** [Instruções passo a passo: testando um projeto \(C\+\+\)](../ide/walkthrough-testing-a-project-cpp.md)  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [DELETE\_PENDING\_Building and Debugging](http://msdn.microsoft.com/pt-br/9f6ba537-5ea0-46fb-b6ba-b63d657d84f1)