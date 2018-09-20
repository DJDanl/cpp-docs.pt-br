---
title: Referência da linguagem C++ | Microsoft Docs
ms.custom: index-page
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- language reference
- C++, language reference
- language reference, Visual C++
- Visual C++, language reference
ms.assetid: 4be9cacb-c862-4391-894a-3a118c9c93ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4fdf0980b8994c313349fd30f05e667b9c0cd461
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377092"
---
# <a name="c-language-reference"></a>Referência da linguagem C++

Esta referência explica a linguagem de programação C++ conforme implementada no Microsoft Visual C++. A organização se baseia *The Annotated C++ Reference Manual* Margaret Ellis e Bjarne Stroustrup e no padrão de internacional de C++ ANSI/ISO (ISO/IEC FDIS 14882). As implementações específicas da Microsoft de recursos da linguagem C++ são incluídas.

Para uma visão geral das práticas de programação do C++ moderno, consulte [bem-vindo de volta ao C++](welcome-back-to-cpp-modern-cpp.md).

Consulte as tabelas a seguir para localizar rapidamente uma palavra-chave ou um operador:

- [Palavras-chave C++](../cpp/keywords-cpp.md)

- [Operadores C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)

## <a name="in-this-section"></a>Nesta seção

[Convenções lexicais](../cpp/lexical-conventions.md)<br/>
Elementos lexicais fundamentais de um programa C++: tokens, comentários, operadores, palavras-chave, pontuadores, literais. Além disso, conversão de arquivo, precedência/associatividade de operadores.

[Conceitos básicos](../cpp/basic-concepts-cpp.md)<br/>
Escopo, vínculo, inicialização e encerramento do programa, classes de armazenamento e tipos.

[Conversões padrão](../cpp/standard-conversions.md)<br/>
Conversões de tipo entre tipos internos ou "fundamentais". Além disso, conversões aritméticas e conversões entre ponteiro, referência e tipos de ponteiro a membro.

[Operadores, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
Os operadores em C++.

[Expressões](../cpp/expressions-cpp.md)<br/>
Tipos de expressões, semântica de expressões, tópicos de referência sobre operadores, conversão e operadores de conversão, informações de tipo de tempo de execução.

[Expressões Lambda](../cpp/lambda-expressions-in-cpp.md)<br/>
Uma técnica de programação que define implicitamente uma classe de objeto de função e constrói um objeto de função desse tipo de classe.

[Instruções](../cpp/statements-cpp.md)<br/>
Expressão, nulo, composto, seleção, iteração, salto e instruções de declaração.

[Declarações e definições](declarations-and-definitions-cpp.md)<br/>
Especificadores de classe de armazenamento, definições de função, inicializações, enumerações **classe**, **struct**, e **união** declarações, e **typedef**  declarações. Além disso, **embutido** funções, **const** palavra-chave, namespaces.

[Classes, estruturas e uniões](../cpp/classes-and-structs-cpp.md)<br/>
Introdução a classes, estruturas e uniões. Além disso, funções de membro, funções de membro especial, membros de dados, campos de bits, **isso** ponteiro, classes aninhadas.

[Classes derivadas](../cpp/inheritance-cpp.md)<br/>
Herança única e múltipla, **virtual** funções, várias classes base, **abstrata** classes, regras de escopo. Além disso, o **super** e **interface** palavras-chave.

[Controle de acesso de membro](../cpp/member-access-control-cpp.md)<br/>
Controlando o acesso a membros de classe: **pública**, **privada**, e **protegido** palavras-chave. Funções e classes amigas.

[Sobrecarga](operator-overloading.md)<br/>
Operadores sobrecarregados, regras para sobrecarga de operador.

[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)<br/>
Tratamento de exceções C++, SEH (manipulação de exceção estruturada), palavras-chave usadas na escrita de instruções de tratamento de exceções.

[Asserção e mensagens fornecidas pelo usuário](../cpp/assertion-and-user-supplied-messages-cpp.md)<br/>
`#error` diretiva, o **static_assert** palavra-chave, o `assert` macro.

[Modelos](../cpp/templates-cpp.md)<br/>
Especificações de modelo, modelos de função, modelos de classe **typename** palavra-chave, modelos versus macros, modelos e ponteiros inteligentes.

[Manipulação de eventos](../cpp/event-handling.md)<br/>
Eventos de declaração e manipuladores de eventos.

[Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)<br/>
Modificadores específicos do Microsoft C++. Memória de endereçamento, convenções de chamada, **naked** funções, atributos de classe de armazenamento estendidos (**declspec**), **__w64**.

[Assembler embutido](../assembler/inline/inline-assembler.md)<br/>
Usando a linguagem de assembly e C++ no **ASM** blocos.

[Suporte para COM do compilador](../cpp/compiler-com-support.md)<br/>
Uma referência a classes específicas da Microsoft e funções globais usadas para oferecer suporte a tipos COM.

[Extensões da Microsoft](../cpp/microsoft-extensions.md)<br/>
Extensões da Microsoft para C++.

[Comportamento não padrão](../cpp/nonstandard-behavior.md)<br/>
Informações sobre comportamento não padrão do compilador do Visual C++.

[Bem-vindo outra vez ao C++](welcome-back-to-cpp-modern-cpp.md)<br/>
Uma visão geral de programação C++ moderna práticas para escrever programas de seguros, corretos e eficientes.

## <a name="related-sections"></a>Seções relacionadas

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)<br/>
Material de referência sobre o uso do Visual C++ para focar no common language runtime.

[Referência de build C/C++](../build/reference/c-cpp-building-reference.md)<br/>
Opções do compilador, opções de vinculador e outras ferramentas de compilação.

[Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)<br/>
Material de referência sobre pragmas, diretivas de pré-processador, macros predefinidas e o pré-processador.

[Bibliotecas do Visual C++](../standard-library/cpp-standard-library-reference.md)<br/>
Uma lista de links para as páginas iniciais de referência das várias bibliotecas do Visual C++.

## <a name="see-also"></a>Consulte também

[Referência da linguagem C](../c-language/c-language-reference.md)