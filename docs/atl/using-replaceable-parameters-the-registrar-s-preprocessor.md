---
title: "Usando par&#226;metros substitu&#237;veis (pr&#233;-processador do registrador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "AddReplacement"
  - "ClearReplacements"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "% DE MÓDULO"
ms.assetid: 0b376994-84a6-4967-8d97-8c01dfc94efe
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando par&#226;metros substitu&#237;veis (pr&#233;-processador do registrador)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Parâmetros substituíveis permitem que o cliente do registrador especificar dados de tempo de execução. Para fazer isso, o registrador mantém um mapa de substituição no qual ele insere os valores associados com os parâmetros substituíveis em seu script. O registrador torna essas entradas em tempo de execução.  
  
##  <a name="_atl_using_.25.module.25"></a> Usando o módulo %  
 O [Assistente de controle ATL](../atl/reference/atl-control-wizard.md) automaticamente gera um script que usa `%MODULE%`. ATL usa esse parâmetro substituível para o local real do seu servidor DLL ou EXE.  
  
## Concatenação de dados de tempo de execução com dados de Script  
 Outro uso do pré\-processador é concatenar dados de tempo de execução com dados de script. Por exemplo, suponha que uma entrada é necessário que contém um caminho completo para um módulo com a cadeia de caracteres "`, 1`" acrescentado ao final. Primeiro, defina a expansão do seguinte:  
  
```  
'MySampleKey' = s '%MODULE%, 1'  
```  
  
 Em seguida, antes de chamar um script processando métodos listados na [chamar Scripts](../atl/invoking-scripts.md), adicione uma substituição para o mapa:  
  
 [!CODE [NVC_ATL_Utilities#113](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#113)]  
  
 Durante a análise do script, o registrador expande `'%MODULE%, 1'` para `c:\mycode\mydll.dll, 1`.  
  
> [!NOTE]
>  Em um script de registrador, 4K é o tamanho máximo de token. \(Um token é qualquer elemento reconhecível na sintaxe\). Isso inclui os tokens que foram criados ou expandidos pelo pré\-processador.  
  
> [!NOTE]
>  Para substituir valores de substituição em tempo de execução, remova a chamada no script para o [DECLARE\_REGISTRY\_RESOURCE](../Topic/DECLARE_REGISTRY_RESOURCE.md) ou [DECLARE\_REGISTRY\_RESOURCEID](../Topic/DECLARE_REGISTRY_RESOURCEID.md) macro. Em vez disso, substitua\-o pelo seu próprio `UpdateRegistry` método que chama [CAtlModule::UpdateRegistryFromResourceD](../Topic/CAtlModule::UpdateRegistryFromResourceD.md) ou [CAtlModule::UpdateRegistryFromResourceS](../Topic/CAtlModule::UpdateRegistryFromResourceS.md), e passar a matriz de **\_ATL\_REGMAP\_ENTRY** estruturas. A matriz de **\_ATL\_REGMAP\_ENTRY** deve ter pelo menos uma entrada é definida como {**nulo**,**nulo**}, e essa entrada deve ser sempre a última entrada. Caso contrário, um erro de violação de acesso será gerado quando **UpdateRegistryFromResource** é chamado.  
  
> [!NOTE]
>  Ao criar um projeto que produz um executável, ATL adiciona automaticamente aspas ao redor do nome de caminho criado em tempo de execução com o **módulo %** parâmetro de script do registrador. Se você não quiser que o nome do caminho para incluir as aspas, use o novo **% MODULE\_RAW %** parâmetro em vez disso.  
>   
>  Ao criar um projeto que gera uma DLL, ATL não adicionará aspas para o nome do caminho se **módulo %** ou **MODULE\_RAW %** é usado.  
  
## Consulte também  
 [Criando scripts de escrivão](../Topic/Creating%20Registrar%20Scripts.md)