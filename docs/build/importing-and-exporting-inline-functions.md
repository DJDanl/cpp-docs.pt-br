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

As funções importadas podem ser definidas como inline. O efeito é aproximadamente o mesmo que definir uma função padrão em linha; chamadas para a função são expandidas para código inline, muito parecido com uma macro. Isso é principalmente útil como uma maneira de apoiar classes C++ em uma DLL que pode inline algumas de suas funções de membro para eficiência.

Uma característica de uma função inline importada é que você pode pegar seu endereço em C++. O compilador retorna o endereço da cópia da função inline que reside na DLL. Outra característica das funções inline importadas é que você pode inicializar dados locais estáticos da função importada, ao contrário dos dados importados globais.

> [!CAUTION]
> Você deve ter cuidado ao fornecer funções inline importadas, pois elas podem criar a possibilidade de conflitos de versão. Uma função inline é expandida para o código do aplicativo; portanto, se você reescrever a função mais tarde, ela não será atualizada a menos que o aplicativo em si seja recompilado. (Normalmente, as funções dll podem ser atualizadas sem reconstruir os aplicativos que as usam.)

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de um DLL](exporting-from-a-dll.md)

- [Exportar de uma DLL usando . Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec(dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportação e importação usando AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C++ para uso em executáveis em linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

## <a name="see-also"></a>Confira também

[Importando e exportando](importing-and-exporting.md)
