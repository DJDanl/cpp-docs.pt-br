---
title: Copiar propriedades do projeto de origem (Linux C++)
ms.date: 10/16/2019
ms.assetid: 1a44230d-5dd8-4d33-93b4-e77e03e00150
ms.openlocfilehash: 393f1b92bb5185bcd5ce93999e0c13f7d370e78d
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924543"
---
# <a name="copy-sources-project-properties-linux-c"></a>Copiar propriedades do projeto de origem (Linux C++)

::: moniker range="msvc-140"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=msvc-150"

As propriedades definidas nesta página de propriedades aplicam-se a todos os arquivos no projeto, exceto aos que têm as propriedades no nível do arquivo definidas.

| Propriedade | Descrição |
|--|--|
| Origens para copiar | Especifica as fontes a serem copiadas para o sistema remoto. Alterar essa lista pode mudar ou afetar de algum outro modo a estrutura de diretórios em que os arquivos são copiados para o sistema remoto. |
| Fontes de dados | Especifica se as fontes devem ser copiadas para o sistema remoto. |
| Fontes adicionais a serem copiadas | Especifica as fontes adicionais a serem copiadas para o sistema remoto. Opcionalmente, especifique pares de mapeamento local para remoto usando uma sintaxe como esta: fulllocalpath1: = fullremotepath1; fulllocalpath2: = fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto. |

@SourcesToCopyRemotely e @DataFilesToCopyRemotely consulte grupos de itens no arquivo de projeto. Para modificar quais fontes ou arquivos de dados são copiados remotamente, edite o arquivo *vcxproj* da seguinte maneira:

```xml
<ItemGroup>
   <MyItems Include="foo.txt" />
   <MyItems Include="bar.txt" />
   <DataFilesToCopyRemotely Include="@(MyItems)" />
</ItemGroup>
```

::: moniker-end
