---
title: Conversão boxing (C++/CLI)
ms.date: 11/04/2016
ms.assetid: f4ee27a8-6a34-432d-b9ec-39285d513b23
ms.openlocfilehash: 03304b902ced2c1e9776eeec90142380b984ee45
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230903"
---
# <a name="boxing-ccli"></a>Conversão boxing (C++/CLI)

Boxing é o processo de converter um tipo de valor para o tipo `object` ou para qualquer tipo de interface que é implementado pelo tipo de valor. Quando as caixas Common Language Runtime (CLR) são um tipo de valor, ele encapsula o valor em um `System.Object` e armazena-o no heap gerenciado. A conversão unboxing extrai o tipo de valor do objeto. A conversão boxing é implícita, a conversão unboxing é explícita.

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Como solicitar a Boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)|Descreve como solicitar explicitamente a Boxing em uma variável.|
|[Como usar o gcnew para criar tipos de valor e usar Boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)|Mostra como usar **`gcnew`** o para criar um tipo de valor em caixa que pode ser colocado no heap gerenciado e coletado por lixo.|
|[Como: realizar uma operação de unbox](../dotnet/how-to-unbox.md)|Mostra como unbox e modificar um valor.|
|[Conversões padrão e Boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)|Mostra que uma conversão padrão é escolhida pelo compilador em uma conversão que requer boxing.|
|[Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|O artigo de nível superior para programação .NET na documentação do Visual C++.|
