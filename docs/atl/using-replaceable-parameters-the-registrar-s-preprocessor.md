---
title: Usando parâmetros substituíveis (registrador da ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- AddReplacement
- ClearReplacements
dev_langs:
- C++
helpviewer_keywords:
- '%MODULE%'
ms.assetid: 0b376994-84a6-4967-8d97-8c01dfc94efe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 91deabfd14d89c4a26384a14445fc51edbb3ac94
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="using-replaceable-parameters-the-registrar39s-preprocessor"></a>Usando parâmetros substituíveis (o registrador&#39;s pré-processador)
Parâmetros substituíveis permitem que o cliente do registrador especificar dados de tempo de execução. Para fazer isso, o registrador mantém um mapa de substituição em que ele insere os valores associados com os parâmetros substituíveis em seu script. O registrador torna essas entradas de tempo de execução.  
  
##  <a name="_atl_using_.25.module.25"></a> Usando o módulo %  
 O [Assistente de controle ATL](../atl/reference/atl-control-wizard.md) gera automaticamente um script que usa `%MODULE%`. ATL usa esse parâmetro substituível para o local real do seu servidor DLL ou EXE.  
  
## <a name="concatenating-run-time-data-with-script-data"></a>Concatenando os dados de tempo de execução com dados de Script  
 Outro uso do pré-processador é concatenar dados de tempo de execução com dados de script. Por exemplo, suponha que uma entrada é necessário que contém um caminho completo para um módulo com a cadeia de caracteres "`, 1`" anexadas no final. Primeiro, defina a expansão do seguinte:  
  
```  
'MySampleKey' = s '%MODULE%, 1'  
```  
  
 Em seguida, antes de chamar um script de processamento métodos listados na [invocar Scripts](../atl/invoking-scripts.md), adicione uma substituição para o mapa:  
  
 [!code-cpp[NVC_ATL_Utilities#113](../atl/codesnippet/cpp/using-replaceable-parameters-the-registrar-s-preprocessor_1.cpp)]  
  
 Durante a análise do script, expande o registrador `'%MODULE%, 1'` para `c:\mycode\mydll.dll, 1`.  
  
> [!NOTE]
>  Em um script de registrador, 4K é o tamanho máximo do token. (Um token é qualquer elemento reconhecível na sintaxe.) Isso inclui os tokens que foram criados ou expandidos do pré-processador.  
  
> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, remova a chamada no script para o [DECLARE_REGISTRY_RESOURCE](../atl/reference/registry-macros.md#declare_registry_resource) ou [DECLARE_REGISTRY_RESOURCEID](../atl/reference/registry-macros.md#declare_registry_resourceid) macro. Em vez disso, substituí-lo com seus próprios `UpdateRegistry` método chama [CAtlModule::UpdateRegistryFromResourceD](../atl/reference/catlmodule-class.md#updateregistryfromresourced) ou [CAtlModule::UpdateRegistryFromResourceS](../atl/reference/catlmodule-class.md#updateregistryfromresources)e passar a matriz de **_ATL_REGMAP_ENTRY** estruturas. A matriz de **_ATL_REGMAP_ENTRY** deve ter pelo menos uma entrada que é definida como {**nulo**,**nulo**}, e essa entrada deve ser sempre a última entrada. Caso contrário, um erro de violação de acesso será gerado quando **UpdateRegistryFromResource** é chamado.  
  
> [!NOTE]
>  Ao criar um projeto que gera um executável, ATL adiciona automaticamente criada em tempo de execução com o nome do caminho entre aspas o **módulo %** parâmetro do script de registrador. Se você não quiser que o nome do caminho para incluir as aspas, use o novo **MODULE_RAW %** parâmetro em vez disso.  
>   
>  Ao criar um projeto que gera uma DLL, ATL não adicionará aspas para o nome do caminho se **módulo %** ou **MODULE_RAW %** é usado.  
  
## <a name="see-also"></a>Consulte também  
 [Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

