---
title: Importando e exportando funções embutidas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- exporting functions [C++], inline functions
- inline functions [C++], importing
- DLLs [C++], importing
- importing functions [C++]
- DLLs [C++], exporting from
- importing inline functions [C++]
- inline functions [C++], exporting
- functions [C++], importing
- functions [C++], exporting
ms.assetid: 89f488f8-b078-40fe-afd7-80bd7840057b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 431b7c3becffb4e5b2543984fd66cae0a1507738
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726551"
---
# <a name="importing-and-exporting-inline-functions"></a>Importando e exportado funções embutidas

Funções importadas podem ser definidas como embutidos. O efeito é aproximadamente o mesmo que definir uma padrão de função embutida; chamadas para a função são expandidas no código embutido, assim como uma macro. Isso é útil principalmente como uma maneira de dar suporte a C++ classes em uma DLL isso de forma embutida talvez alguns dos seus membros de funções para maior eficiência.

Um recurso de uma função importada embutida é que você pode usar seu endereço em C++. O compilador retorna o endereço da cópia da função embutida que reside na DLL. Outro recurso de funções embutidas importadas é que você pode inicializar os dados locais estáticos da função importada, ao contrário dos dados importados globais.

> [!CAUTION]
>  Você deve tenha cuidado ao fornecer importado funções embutidas, pois eles podem criar a possibilidade de conflitos de versão. Uma função embutida é expandida em código do aplicativo; Portanto, se você posteriormente reescrever a função, ele não for atualizado, a menos que o aplicativo em si é recompilado. (Normalmente, funções de DLL podem ser atualizadas sem recompilar os aplicativos que usá-los.)

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportação de uma DLL](../build/exporting-from-a-dll.md)

- [Exportar de uma DLL usando. Arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinar qual método de exportação usar](../build/determining-which-exporting-method-to-use.md)

- [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)

## <a name="see-also"></a>Consulte também

[Importando e exportando](../build/importing-and-exporting.md)