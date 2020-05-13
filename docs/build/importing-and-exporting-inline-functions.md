---
title: Importação e exportação de funções embutidas
ms.date: 11/04/2016
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
ms.openlocfilehash: abb0443ab8fbd315524350caaff34e0250147ed2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328513"
---
# <a name="importing-and-exporting-inline-functions"></a>Importação e exportação de funções embutidas

As funções importadas podem ser definidas como embutidas. O efeito é praticamente o mesmo que definir uma função padrão embutida; as chamadas para a função são expandidas em código embutido, de forma semelhante a uma macro. Isso é principalmente útil como uma maneira de dar suporte a classes C++ em uma DLL que pode embutir algumas de suas funções de membro para eficiência.

Um recurso de uma função embutida importada é que você pode pegar seu endereço em C++. O compilador retorna o endereço da cópia da função embutida que reside na DLL. Outro recurso das funções embutidas importadas é que você pode inicializar dados locais estáticos da função importada, diferentemente dos dados importados globalmente.

> [!CAUTION]
> Você deve ter cuidado ao fornecer funções embutidas importadas, pois elas podem criar a possibilidade de conflitos de versão. Uma função embutida é expandida no código do aplicativo; Portanto, se você reescrever posteriormente a função, ela não será atualizada, a menos que o próprio aplicativo seja recompilado. (Normalmente, as funções de DLL podem ser atualizadas sem recriar os aplicativos que as utilizam.)

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL](exporting-from-a-dll.md)

- [Exportar de uma DLL usando. Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C++ para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

## <a name="see-also"></a>Confira também

[Importando e exportando](importing-and-exporting.md)
