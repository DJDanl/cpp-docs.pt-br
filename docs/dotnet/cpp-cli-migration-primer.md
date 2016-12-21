---
title: "Primer de migra&#231;&#227;o C++/CLI | Microsoft Docs"
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
  - "C++/CLI Versão 2"
  - "C++/CLI Versão 2, extensões gerenciadas"
  - "Extensões Gerenciadas para C++, atualizando sintaxe"
  - "migração [C++], C++/CLI Versão 2"
  - "atualizando aplicativos Visual C++, Extensões Gerenciadas para C++ para a sintaxe Visual C++ 2005"
ms.assetid: 8ec926b5-73f6-4f0c-bcdf-5203d293849a
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Primer de migra&#231;&#227;o C++/CLI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este é um guia para mover seus programas do Visual C\+\+ de Extensões Gerenciadas para C\+\+ para o [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  Para um resumo da lista de verificação de alterações sintáticas, consulte [\(NOTINBUILD\)Managed Extensions for C\+\+ Syntax Upgrade Checklist](http://msdn.microsoft.com/pt-br/edbded88-7ef3-4757-bd9d-b8f48ac2aada).  
  
 C\+\+\/CLI estende um paradigma de programação de componente dinâmico para a linguagem padrão ISO\-C\+\+.  O novo idioma oferece alguns aprimoramentos significativos em Extensões Gerenciadas.  Esta seção fornece uma lista enumerada dos recursos de linguagem das Extensões Gerenciadas para C\+\+ e seus mapeamentos para [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)], onde tal mapeamento existe e aponta para as construções para as quais não existem mapeamentos.  
  
## Nesta seção  
 [Destaques de alterações \(C\+\+\/CLI\)](../dotnet/outline-of-changes-cpp-cli.md)  
 Um contorno de alto nível para referência rápida, fornecendo uma listagem das alterações em cinco categorias gerais.  
  
 [Palavras\-chave da linguagem \(C\+\+\/CLI\)](../Topic/Language%20Keywords%20\(C++-CLI\).md)  
 Descreve alterações em palavras\-chave da linguagem, incluindo a remoção do sublinhado duplo e a introdução de palavras\-chave contextuais e espaçadas.  
  
 [Tipos gerenciados \(C\+\+\/CL\)](../dotnet/managed-types-cpp-cl.md)  
 Observe alterações sintáticas na declaração do Common Type System \(CTS\) – isso inclui alterações na declaração de classes, matrizes \(incluindo a matriz de parâmetros\), enum, e assim por diante.  
  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)  
 Apresenta as alterações que envolvem membros de classe como propriedades escalares, propriedades de índice, operadores, delegados e eventos.  
  
 [Tipos de valor e seus comportamentos \(C\+\+\/CLI\)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)  
 Foco nos tipos de valor e na nova família de ponteiros interiores e fixos.  Também debate um número de alterações significativas de semântica como a introdução de boxing implícito, a imutabilidade de tipos boxed value e a remoção de suporte para construtores padrão dentro das classes de valor.  
  
 [Alteração geral em linguagens](../Topic/General%20Language%20Changes%20\(C++-CLI\).md)  
 Detalha as alterações semânticas, como o suporte para notação de conversão, comportamento do literal de cadeia de caracteres e alterações na semântica entre ISO\-C\+\+ e C\+\+\/CLI.  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)   
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)