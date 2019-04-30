---
title: Conversão boxing (C++/CLI)
ms.date: 11/04/2016
ms.assetid: f4ee27a8-6a34-432d-b9ec-39285d513b23
ms.openlocfilehash: 3f756eaef59c24ca5b82c485bd8352dffe9fb1db
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345762"
---
# <a name="boxing-ccli"></a>Conversão boxing (C++/CLI)

Conversão boxing é o processo de conversão de um tipo de valor para o tipo `object` ou para qualquer tipo de interface é implementado pelo tipo de valor. Quando o common language runtime (CLR) caixas de um tipo de valor, ele encapsula o valor em um `System.Object` e os armazena no heap gerenciado. A conversão unboxing extrai o tipo de valor do objeto. A conversão boxing é implícita, a conversão unboxing é explícita.

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Como: solicitar explicitamente uma conversão boxing](../dotnet/how-to-explicitly-request-boxing.md)|Descreve como solicitar explicitamente a conversão boxing em uma variável.|
|[Como: usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)|Mostra como usar `gcnew` para criar um tipo de valor demarcado que pode ser colocado no heap gerenciado, coleta de lixo.|
|[Como: realizar uma operação de unbox](../dotnet/how-to-unbox.md)|Mostra como converter e modificar um valor.|
|[Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)|Mostra que uma conversão padrão será escolhida pelo compilador em vez de uma conversão que requer boxing.|
|[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)|O artigo de nível superior para a programação do .NET na documentação do Visual C++.|