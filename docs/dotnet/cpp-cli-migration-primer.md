---
title: C + + c++ Primer de migração | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- C++/CLI Version 2
- upgrading Visual C++ applications, Managed Extensions for C++ to Visual C++ 2005 syntax
- migration [C++], C++/CLI Version 2
- Managed Extensions for C++, upgrading syntax
- C++/CLI Version 2, managed extensions
ms.assetid: 8ec926b5-73f6-4f0c-bcdf-5203d293849a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 88b32ea226971c0fa5b6d269a8992629c3c4de77
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385425"
---
# <a name="ccli-migration-primer"></a>Primer de migração C++/CLI

Este é um guia para mover seus programas do Visual C++ de extensões gerenciadas para C++ para Visual C++.

C + + c++ /CLI estende um paradigma de programação de componente dinâmico para o idioma padrão do ISO C++. O novo idioma oferece vários aprimoramentos significativos em extensões gerenciadas. Esta seção fornece uma lista enumerada das extensões gerenciadas para recursos da linguagem C++ e seus mapeamentos para o Visual C++, onde tal mapeamento existe e aponta para as construções para o qual não existe mapeamento.

## <a name="in-this-section"></a>Nesta seção

[Descrição das alterações (C++/CLI)](../dotnet/outline-of-changes-cpp-cli.md)<br/>
Um contorno de alto nível para referência rápida, fornecendo uma listagem das alterações em cinco categorias gerais.

[Palavras-chave da linguagem (C++/CLI)](../dotnet/language-keywords-cpp-cli.md)<br/>
Aborda as alterações em palavras-chave, incluindo a remoção do sublinhado duplo e a introdução de palavras-chave contextuais e espaçadas.

[Tipos gerenciados (C++ /CLI CL)](../dotnet/managed-types-cpp-cl.md)<br/>
Alterações sintáticas na declaração do Common Type System (CTS) – isso inclui alterações na declaração de classes, matrizes (incluindo a matriz de parâmetros), enums e assim por diante.

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)<br/>
Apresenta as alterações que envolvem membros de classe como propriedades escalares, propriedades do índice, operadores, delegados e eventos.

[Tipos de valor e seus comportamentos (C++/CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)<br/>
Se concentra em tipos de valor e a nova família de ponteiros interiores e fixos. Ele também discute algumas das alterações significativas de semântica como a introdução de conversão boxing implícita, a imutabilidade de tipos boxed value e a remoção do suporte para construtores padrão dentro de classes de valor.

[Alterações gerais na linguagem (C++/CLI)](../dotnet/general-language-changes-cpp-cli.md)<br/>
Detalha as alterações semânticas, como suporte para notação de conversão de cadeia de caracteres literal comportamento e as alterações na semântica entre ISO-c e C + + / CLI.

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)<br/>
[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)