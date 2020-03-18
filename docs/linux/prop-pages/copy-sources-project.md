---
title: Copiar propriedades do projeto de origem (Linux C++)
ms.date: 10/16/2019
ms.assetid: 1a44230d-5dd8-4d33-93b4-e77e03e00150
ms.openlocfilehash: 732a13520a223f1aa73733cd4098c247052f8d3b
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441381"
---
# <a name="copy-sources-project-properties-linux-c"></a>Copiar propriedades do projeto de origem (Linux C++)

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

As propriedades definidas nesta página de propriedades aplicam-se a todos os arquivos no projeto, exceto aos que têm as propriedades no nível do arquivo definidas.

| Propriedade | Descrição |
|--|--|
| Origens para copiar | Especifica as fontes a serem copiadas para o sistema remoto. Alterar essa lista pode mudar ou afetar de algum outro modo a estrutura de diretórios em que os arquivos são copiados para o sistema remoto. |
| Fontes de dados | Especifica se as fontes devem ser copiadas para o sistema remoto. |
| Fontes adicionais a serem copiadas | Especifica as fontes adicionais a serem copiadas para o sistema remoto. Opcionalmente, especifique pares de mapeamento local para remoto usando uma sintaxe como esta: fulllocalpath1: = fullremotepath1; fulllocalpath2: = fullremotepath2, em que um arquivo local pode ser copiado para o local remoto especificado no sistema remoto. |

@SourcesToCopyRemotely e @DataFilesToCopyRemotely se referem a grupos de itens no arquivo de projeto. Para modificar quais fontes ou arquivos de dados são copiados remotamente, edite o arquivo *vcxproj* da seguinte maneira:

```xml
<ItemGroup>
   <MyItems Include="foo.txt" />
   <MyItems Include="bar.txt" />
   <DataFilesToCopyRemotely Include="@(MyItems)" />
</ItemGroup>
```

::: moniker-end
