---
title: Conversão boxing (C++/CLI)
ms.date: 11/04/2016
ms.assetid: f4ee27a8-6a34-432d-b9ec-39285d513b23
ms.openlocfilehash: df0e220c4f744e78aa5bedce4f956b726f524ff4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208817"
---
# <a name="boxing-ccli"></a>Conversão boxing (C++/CLI)

Boxing é o processo de converter um tipo de valor para o tipo `object` ou para qualquer tipo de interface que é implementado pelo tipo de valor. Quando as caixas de Common Language Runtime (CLR) um tipo de valor, ele encapsula o valor em um `System.Object` e o armazena no heap gerenciado. A conversão unboxing extrai o tipo de valor do objeto. A conversão boxing é implícita, a conversão unboxing é explícita.

## <a name="related-articles"></a>Artigos relacionados

|Title|DESCRIÇÃO|
|-----------|-----------------|
|[Como solicitar uma conversão boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)|Descreve como solicitar explicitamente a Boxing em uma variável.|
|[Como usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)|Mostra como usar `gcnew` para criar um tipo de valor em caixa que pode ser colocado no heap gerenciado e coletado por lixo.|
|[Como reverter uma conversão boxing](../dotnet/how-to-unbox.md)|Mostra como unbox e modificar um valor.|
|[Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)|Mostra que uma conversão padrão é escolhida pelo compilador em uma conversão que requer boxing.|
|[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|O artigo de nível superior para programação .NET na documentação visual C++ .|
