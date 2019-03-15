---
title: Usando parâmetros substituíveis (registrador da ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- '%MODULE%'
ms.assetid: 0b376994-84a6-4967-8d97-8c01dfc94efe
ms.openlocfilehash: 1c772c0493b351d8452400a4fb1e3949ab6f28f2
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57814027"
---
# <a name="using-replaceable-parameters-the-registrar39s-preprocessor"></a>Usando parâmetros substituíveis (registrador de&#39;s pré-processador)

Parâmetros substituíveis permitem que o cliente de um registrador especificar dados de tempo de execução. Para fazer isso, o registrador mantém um mapa de substituição no qual ele insere os valores associados com os parâmetros substituíveis em seu script. O registrador torna essas entradas em tempo de execução.

##  <a name="_atl_using_.25.module.25"></a> Usando o módulo %

O [Assistente de controle ATL](../atl/reference/atl-control-wizard.md) automaticamente gera um script que usa `%MODULE%`. ATL usa esse parâmetro substituível para o local real do seu servidor DLL ou EXE.

## <a name="concatenating-run-time-data-with-script-data"></a>Concatenando os dados de tempo de execução com os dados de Script

Outro uso do pré-processador é concatenar dados de tempo de execução com os dados de script. Por exemplo, suponha que uma entrada é necessário que contém um caminho completo para um módulo com a cadeia de caracteres "`, 1`" acrescentado ao final. Primeiro, defina a expansão do seguinte:

```
'MySampleKey' = s '%MODULE%, 1'
```

Em seguida, antes de chamar um dos scripts processamento métodos listados na [invocar Scripts](../atl/invoking-scripts.md), adicione uma substituição para o mapa:

[!code-cpp[NVC_ATL_Utilities#113](../atl/codesnippet/cpp/using-replaceable-parameters-the-registrar-s-preprocessor_1.cpp)]

Durante a análise do script, o registrador expande `'%MODULE%, 1'` para `c:\mycode\mydll.dll, 1`.

> [!NOTE]
>  Em um script de registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe). Isso inclui os tokens que foram criados ou expandidos pelo pré-processador.

> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, remova a chamada no script para o [DECLARE_REGISTRY_RESOURCE](../atl/reference/registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](../atl/reference/registry-macros.md#declare_registry_resourceid) macro. Em vez disso, substitua-o com seus próprios `UpdateRegistry` método que chama [CAtlModule::UpdateRegistryFromResourceD](../atl/reference/catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](../atl/reference/catlmodule-class.md#updateregistryfromresources)e passar a matriz de _ATL_REGMAP_ Estruturas de entrada. Sua matriz de _ATL_REGMAP_ENTRY deve ter pelo menos uma entrada é definida como {NULL, NULL}, e essa entrada deve ser sempre a última entrada. Caso contrário, um erro de violação de acesso será gerado quando `UpdateRegistryFromResource` é chamado.

> [!NOTE]
>  Ao criar um projeto que produz um executável, ATL adiciona automaticamente aspas ao redor do nome de caminho criado no tempo de execução com o **módulo %** parâmetro do script de registrador. Se você não quiser que o nome do caminho para incluir as aspas, use a nova **MODULE_RAW %** parâmetro em vez disso.
>
>  Ao compilar um projeto que gera uma DLL, ATL não adicionará aspas para o nome do caminho se **% % do módulo** ou **MODULE_RAW %** é usado.

## <a name="see-also"></a>Consulte também

[Criando scripts do Registrador](../atl/creating-registrar-scripts.md)
