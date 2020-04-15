---
title: Usando parâmetros substituíveis (REGISTRADOr ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- '%MODULE%'
ms.assetid: 0b376994-84a6-4967-8d97-8c01dfc94efe
ms.openlocfilehash: 2474db2de384baa9113ed39aef4d3d9c9048903d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329223"
---
# <a name="using-replaceable-parameters-the-registrar39s-preprocessor"></a>Usando parâmetros substituíveis (o pré-processador do&#39;registrador)

Os parâmetros substituíveis permitem que o cliente do Registrador especifique dados de tempo de execução. Para isso, o Registrador mantém um mapa de substituição no qual ele insere os valores associados aos parâmetros substituíveis em seu script. O Registrador faz essas entradas em tempo de execução.

## <a name="using-module"></a><a name="_atl_using_.25.module.25"></a>Usando %MODULE%

O [assistente de controle ATL](../atl/reference/atl-control-wizard.md) gera `%MODULE%`automaticamente um script que usa . A ATL usa este parâmetro substituível para a localização real da DLL ou EXE do seu servidor.

## <a name="concatenating-run-time-data-with-script-data"></a>Concatenando dados de tempo de execução com dados de script

Outro uso do pré-processador é concatenar dados de tempo de execução com dados de script. Por exemplo, suponha que uma entrada é necessária que`, 1`contenha um caminho completo para um módulo com a string " " anexada no final. Primeiro, defina a seguinte expansão:

```
'MySampleKey' = s '%MODULE%, 1'
```

Em seguida, antes de chamar um dos métodos de processamento de script listados em [Invocação de Scripts,](../atl/invoking-scripts.md)adicione uma substituição ao mapa:

[!code-cpp[NVC_ATL_Utilities#113](../atl/codesnippet/cpp/using-replaceable-parameters-the-registrar-s-preprocessor_1.cpp)]

Durante a análise do script, o `'%MODULE%, 1'` Registrador expande-se para `c:\mycode\mydll.dll, 1`.

> [!NOTE]
> Em um script Registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe.) Isso inclui tokens que foram criados ou expandidos pelo pré-processador.

> [!NOTE]
> Para substituir os valores de substituição no tempo de execução, remova a chamada no script para a [DECLARE_REGISTRY_RESOURCE](../atl/reference/registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](../atl/reference/registry-macros.md#declare_registry_resourceid) macro. Em vez disso, `UpdateRegistry` substitua-o pelo seu próprio método que chama [CAtlModule::UpdateRegistryFromResourceD](../atl/reference/catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](../atl/reference/catlmodule-class.md#updateregistryfromresources)e passe sua matriz de estruturas de _ATL_REGMAP_ENTRY. Sua matriz de _ATL_REGMAP_ENTRY deve ter pelo menos uma entrada definida como {NULL,NULL}, e esta entrada deve ser sempre a última entrada. Caso contrário, um erro de `UpdateRegistryFromResource` violação de acesso será gerado quando for chamado.

> [!NOTE]
> Ao construir um projeto que produz um executável, o ATL adiciona automaticamente aspas em torno do nome do caminho criado no tempo de execução com o parâmetro de script do registrador **%MODULE%** . Se você não quiser que o nome do caminho inclua as aspas, use o novo parâmetro **%MODULE_RAW%.**
>
> Ao construir um projeto que produz uma DLL, a ATL não adicionará aspas ao nome do caminho se **%MODULE%** ou **%MODULE_RAW%** for em uso.

## <a name="see-also"></a>Confira também

[Criando scripts de registrador](../atl/creating-registrar-scripts.md)
