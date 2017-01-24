---
title: "Implementando p&#225;ginas de propriedades | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IPropertyPage"
  - "Classe IPropertyPage2"
  - "páginas de propriedades, implementando"
ms.assetid: 62f29440-33a7-40eb-a1ef-3634c95f640c
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando p&#225;ginas de propriedades
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As páginas de propriedades são objetos COM que implementam `IPropertyPage` ou a interface de **IPropertyPage2** .  ATL fornece suporte para implementar páginas de propriedades com [Assistente da página de propriedades de ATL](../atl/reference/atl-property-page-wizard.md) em [Adicione a caixa de diálogo de classe](../ide/add-class-dialog-box.md).  
  
 Para criar uma página de propriedades usando ATL:  
  
-   Criar ou abrir um projeto do servidor de \(DLL\) de biblioteca de vínculo dinâmico de ATL.  
  
-   Abra [Adicione a caixa de diálogo de classe](../ide/add-class-dialog-box.md) e selecione **Página de Propriedades do ATL**.  
  
-   Verifique se a página de propriedades é compartimento de \(desde que tem uma interface do usuário\).  
  
-   Definir o título, descrição \(cadeia de caracteres de Doc\), e o arquivo de ajuda a ser associado com a página.  
  
-   Adicionar controles ao recurso gerado da caixa de diálogo para atuar como a interface do usuário da página de propriedades.  
  
-   Responder a alterações na interface do usuário da página para executar a validação, atualizar o site da página, ou para atualizar os objetos associados com sua página.  Em particular, [IPropertyPageImpl::SetDirty](../Topic/IPropertyPageImpl::SetDirty.md) chamada quando o usuário fizer alterações na página de propriedades.  
  
-   Opcionalmente substituir os métodos de `IPropertyPageImpl` usando as diretrizes a seguir.  
  
    |Método de IPropertyPageImpl|Substituição quando você quiser…|Anotações|  
    |---------------------------------|--------------------------------------|---------------|  
    |[SetObjects](../Topic/IPropertyPageImpl::SetObjects.md)|Executar verificações básicas de sanidade no número de objetos que estão sendo passadas a sua página e às interfaces que suportam.|Executar seu próprio código antes de chamar a implementação da classe base.  Se os objetos que estão sendo definidos não atendem às suas expectativas, você deve falhar a chamada mais rápido possível.|  
    |[Ativar](../Topic/IPropertyPageImpl::Activate.md)|Inicializar a interface do usuário da página \(por exemplo, definir controles de caixa de diálogo com valores de propriedade atual de objetos, criar controles dinamicamente, ou executa outras inicializações\).|Chamar a implementação da classe base antes de seu código de tal forma que a classe base tem uma possibilidade de criar a janela da caixa de diálogo e todos os controles antes de tentar atualizar a.|  
    |[Aplicar](../Topic/IPropertyPageImpl::Apply.md)|Validar as configurações de propriedade e atualizar os objetos.|Não há necessidade de chamar a implementação da classe base já que não faz nada independentemente de rastreamento a chamada.|  
    |[Desativar](../Topic/IPropertyPageImpl::Deactivate.md)|Limpe de itens relacionados.|A implementação da classe base for a caixa de diálogo que representa a página de propriedades.  Se você precisa limpar antes que a caixa de diálogo seja destruída, você deve adicionar o código antes de chamar a classe base.|  
  
 Para uma implementação da página de propriedades de exemplo, consulte [exemplo: implementando uma página de propriedades](../atl/example-implementing-a-property-page.md).  
  
> [!NOTE]
>  Se você desejar hospedar controles ActiveX em sua página de propriedades, você precisará alterar a derivação de sua classe assistentes gerado.  Substitua **CDialogImpl\<CYourClass\>** com **CAxDialogImpl\<CYourClass\>** na lista de classes base.  
  
## Consulte também  
 [Páginas de propriedade](../atl/atl-com-property-pages.md)   
 [exemplo de ATLPages](../top/visual-cpp-samples.md)