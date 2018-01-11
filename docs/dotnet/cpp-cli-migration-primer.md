---
title: "C + + Primer de migração de CLI | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- C++/CLI Version 2
- upgrading Visual C++ applications, Managed Extensions for C++ to Visual C++ 2005 syntax
- migration [C++], C++/CLI Version 2
- Managed Extensions for C++, upgrading syntax
- C++/CLI Version 2, managed extensions
ms.assetid: 8ec926b5-73f6-4f0c-bcdf-5203d293849a
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1dcbb3b54cbde323cda0856ca68b2281d669cb7b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccli-migration-primer"></a>Primer de migração C++/CLI
Este é um guia para mover seus programas do Visual C++ de extensões gerenciadas para C++ para Visual C++. Para obter um resumo da lista de verificação de alterações de sintaxe, consulte [(NOTINBUILD) das extensões gerenciadas para verificação de atualização de sintaxe de C++](http://msdn.microsoft.com/en-us/edbded88-7ef3-4757-bd9d-b8f48ac2aada).  
  
 C + + CLI estende um paradigma de programação de componente dinâmico para o idioma padrão ISO C++. O novo idioma oferece vários aprimoramentos significativos em extensões gerenciadas. Esta seção fornece uma lista enumerada das extensões gerenciadas para recursos de linguagem do C++ e o seu mapeamento para o Visual C++, onde um mapeamento desse tipo existe e destaca as construções para o qual não existe mapeamento.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Descrição das alterações (C++/CLI)](../dotnet/outline-of-changes-cpp-cli.md)  
 Uma descrição de alto nível para referência rápida, fornecendo uma lista das alterações em cinco categorias gerais.  
  
 [Palavras-chave da linguagem (C++/CLI)](../dotnet/language-keywords-cpp-cli.md)  
 Aborda as alterações nas palavras-chave de idioma, incluindo a remoção de um sublinhado duplo e a introdução de palavras-chave contextuais e espaçadas.  
  
 [Tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md)  
 Examina sintáticas alterações na declaração de sistema de tipo comum (CTS) - isso inclui alterações na declaração de classes, matrizes (incluindo a matriz de parâmetros), enums e assim por diante.  
  
 [Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)  
 Apresenta as alterações que envolvem a membros de classe como propriedades escalares, propriedades do índice, operadores, representantes e eventos.  
  
 [Tipos de valor e seus comportamentos (C++/CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)  
 Se concentra em tipos de valor e a nova família de ponteiros de fixação e interiores. Ele também discute várias alterações significativas semântica, como a introdução de conversão boxing implícita, imutabilidade de tipos de valor boxed e a remoção do suporte para construtores padrão dentro de classes de valor.  
  
 [Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)  
 Alterações semânticas de detalhes, como o suporte para a notação de conversão de cadeia de caracteres literal comportamento e alterações na semântica entre ISO C++ e C + + CLI.  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)   
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)