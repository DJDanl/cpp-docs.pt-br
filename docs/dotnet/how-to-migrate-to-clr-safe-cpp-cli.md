---
title: "Como migrar para /clr:safe (C++/CLI) | Microsoft Docs"
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
  - "Opção de compilador /clr [C++], Migrando para /clr:safe"
  - "migração [C++], assemblies verificáveis"
  - "atualizando aplicativos Visual C++, assemblies verificáveis"
  - "assemblies verificáveis [C++], Migrando para "
ms.assetid: 75f9aae9-1dcc-448a-aa11-2d96f972f9d2
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como migrar para /clr:safe (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ pode gerar componentes verificáveis usando **\/clr:safe**, que faz com que o compilador gerencia erros para cada construção não gerencie o código.  
  
## Comentários  
 Os seguintes problemas gerenciem erros de verificabilidade:  
  
-   Tipos nativos.  Mesmo se não for usada, a declaração de classes nativas, de estruturas, de ponteiros, ou de matrizes impedirá a compilação.  
  
-   Variáveis globais  
  
-   Chamadas de função em qualquer biblioteca não gerenciado, incluindo chamadas de função de Common Language Runtime  
  
-   Uma função verificável não pode conter [Operador static\_cast](../cpp/static-cast-operator.md) para a conversão para baixo.  [Operador static\_cast](../cpp/static-cast-operator.md) pode ser usado para converter entre tipos primitivos, mas para a conversão para baixo, o [safe\_cast](../windows/safe-cast-cpp-component-extensions.md) ou a c a conversão de estilo \(que é implementada como [safe\_cast](../windows/safe-cast-cpp-component-extensions.md)\) deve ser usada.  
  
-   Uma função verificável não pode conter [Operador reinterpret\_cast](../cpp/reinterpret-cast-operator.md) \(ou qualquer equivalente convertido de estilo 2.0 \- c\).  
  
-   Uma função verificável não pode executar a aritmética em [interior\_ptr \(C\+\+\/CLI\)](../windows/interior-ptr-cpp-cli.md).  Só pode atribuir e desreferenciar\-la.  
  
-   Uma função verificável só pode gerar ou captura ponteiros para referenciar tipos, assim os tipos de valores devem ser boxed antes de gerar.  
  
-   Uma função verificável só pode chamar funções verificáveis \(tais que as chamadas para Common Language Runtime não sejam permitidos, incluem `AtEntry`\/`AtExit`, e assim que os construtores globais são desaprovados.\)  
  
-   Uma classe verificável não pode usar <xref:System.Runtime.InteropServices.LayoutKind>.  
  
-   Se estiver compilando EXE, uma função principal não pode declarar nenhum parâmetro, de modo que <xref:System.Environment.GetCommandLineArgs%2A> deve ser usado para recuperar argumentos de linha de comando.  
  
-   Fazendo uma chamada não virtual para uma função virtual.  Por exemplo:  
  
    ```  
    // not_verifiable.cpp  
    // compile with: /clr  
    ref struct A {  
       virtual void Test() {}  
    };  
  
    ref struct B : A {};  
  
    int main() {  
       B^ b1 = gcnew B;  
       b1->A::Test();   // Non-virtual call to virtual function  
    }  
    ```  
  
 Além disso, as seguintes palavras\-chave não podem ser usados no código verificável:  
  
-   [não gerenciado](../preprocessor/managed-unmanaged.md) e pragmas de [bloco](../preprocessor/pack.md)  
  
-   [despido](../Topic/naked%20\(C++\).md) e modificadores de [alinhar](../cpp/align-cpp.md)[\_\_declspec](../cpp/declspec.md)  
  
-   [\_\_asm](../assembler/inline/asm.md)  
  
-   [\_\_based](../cpp/based-grammar.md)  
  
-   [\_\_try](../cpp/try-except-statement.md) e `__except`  
  
## Consulte também  
 [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md)