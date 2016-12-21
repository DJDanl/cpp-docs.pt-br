---
title: "/VERBOSE (imprimir mensagens de progresso) | Microsoft Docs"
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
  - "/verbose"
  - "VC.Project.VCLinkerTool.ShowProgress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /VERBOSE"
  - "dependências [C++], informações de dependência na saída do vinculador"
  - "vinculador [C++], informações de dependência de saída"
  - "vinculando [C++], informações de andamento da sessão"
  - "opção de vinculador Imprimir Mensagens de Andamento"
  - "opção de vinculador VERBOSE"
  - "opção de vinculador -VERBOSE"
ms.assetid: 9c347d98-4c37-4724-a39e-0983934693ab
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /VERBOSE (imprimir mensagens de progresso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/VERBOSE[:{ICF|INCR|LIB|REF|SAFESEH|UNUSEDLIBS}]  
```  
  
## Comentários  
 O vinculador envia informações sobre o andamento da sessão de vinculação à janela **Saída**.  Na linha de comando, as informações são enviadas para a saída padrão e podem ser redirecionadas para um arquivo.  
  
|Opção|Descrição|  
|-----------|---------------|  
|\/VERBOSE|Exibe detalhes sobre o processo de vinculação.|  
|\/VERBOSE:ICF|Exibir informações sobre a atividade do vinculador que resulta do uso de [\/OPT: ICF](../../build/reference/opt-optimizations.md).|  
|\/VERBOSE:INCR|Exibe informações sobre o processo de vinculação incremental.|  
|\/VERBOSE:LIB|Exibe as mensagens de progresso que indicam apenas as bibliotecas pesquisadas.<br /><br /> As informações exibidas incluem o processo de pesquisa de biblioteca e exibem cada nome de biblioteca e de objeto \(com o caminho completo\), o símbolo que está sendo resolvido da biblioteca e uma lista de objetos que referenciam o símbolo.|  
|\/VERBOSE:REF|Exibe informações sobre a atividade do vinculador que resulta do uso de [\/OPT: REF](../../build/reference/opt-optimizations.md).|  
|\/VERBOSE:SAFESEH|Exibe informações sobre os módulos que não são compatíveis com a manipulação de exceção segura quando [\/SAFESEH](../Topic/-SAFESEH%20\(Image%20has%20Safe%20Exception%20Handlers\).md) não é especificado.|  
|\/VERBOSE:UNUSEDLIBS|Exibe informações sobre todos os arquivos da biblioteca que não são usados quando a imagem é criada.|  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Expanda a pasta do **Vinculador**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Adicione a opção à caixa **Opções Adicionais**.  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ShowProgress%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)