---
title: Usando parâmetros substituíveis (registrador ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- '%MODULE%'
ms.assetid: 0b376994-84a6-4967-8d97-8c01dfc94efe
ms.openlocfilehash: debbccea5836fa63282b62ff87573160069fb169
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168677"
---
# <a name="using-replaceable-parameters-the-registrar39s-preprocessor"></a>Usando parâmetros substituíveis (o registrador&#39;s pré-processador)

Os parâmetros substituíveis permitem que o cliente do registrador especifique dados de tempo de execução. Para fazer isso, o registrador mantém um mapa de substituição no qual ele insere os valores associados aos parâmetros substituíveis em seu script. O registrador faz essas entradas em tempo de execução.

## <a name="using-module"></a><a name="_atl_using_.25.module.25"></a>Usando% MODULE%

O [Assistente de controle do ATL](../atl/reference/atl-control-wizard.md) gera automaticamente um script `%MODULE%`que usa o. A ATL usa esse parâmetro substituível para o local real da DLL ou do EXE do seu servidor.

## <a name="concatenating-run-time-data-with-script-data"></a>Concatenando dados de tempo de execução com dados de script

Outro uso do pré-processador é concatenar os dados em tempo de execução com dados de script. Por exemplo, suponha que seja necessária uma entrada que contenha um caminho completo para um módulo com a`, 1`cadeia de caracteres "" anexada no final. Primeiro, defina a seguinte expansão:

```rgs
'MySampleKey' = s '%MODULE%, 1'
```

Em seguida, antes de chamar um dos métodos de processamento de script listados em [invocando scripts](../atl/invoking-scripts.md), adicione uma substituição ao mapa:

[!code-cpp[NVC_ATL_Utilities#113](../atl/codesnippet/cpp/using-replaceable-parameters-the-registrar-s-preprocessor_1.cpp)]

Durante a análise do script, o registrador `'%MODULE%, 1'` se expande para `c:\mycode\mydll.dll, 1`o.

> [!NOTE]
> Em um script de registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe.) Isso inclui tokens que foram criados ou expandidos pelo pré-processador.

> [!NOTE]
> Para substituir valores de substituição em tempo de execução, remova a chamada no script para a [DECLARE_REGISTRY_RESOURCE](../atl/reference/registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](../atl/reference/registry-macros.md#declare_registry_resourceid) macro. Em vez disso, substitua-o `UpdateRegistry` pelo seu próprio método que chama [CAtlModule:: UpdateRegistryFromResourceD](../atl/reference/catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule:: UpdateRegistryFromResourceS](../atl/reference/catlmodule-class.md#updateregistryfromresources)e passe sua matriz de estruturas de _ATL_REGMAP_ENTRY. Sua matriz de _ATL_REGMAP_ENTRY deve ter pelo menos uma entrada definida como {NULL, NULL} e essa entrada sempre deve ser a última entrada. Caso contrário, um erro de violação de acesso será `UpdateRegistryFromResource` gerado quando for chamado.

> [!NOTE]
> Ao criar um projeto que gera um executável, a ATL adiciona automaticamente aspas em volta do nome do caminho criado em tempo de execução com o parâmetro **% Module%** registrar script. Se você não quiser que o nome do caminho inclua as aspas, use o novo parâmetro **% MODULE_RAW%** em vez disso.
>
> Ao criar um projeto que gera uma DLL, a ATL não adicionará aspas ao nome do caminho se **% Module%** ou **% MODULE_RAW%** for usado.

## <a name="see-also"></a>Confira também

[Criando scripts de registrador](../atl/creating-registrar-scripts.md)
