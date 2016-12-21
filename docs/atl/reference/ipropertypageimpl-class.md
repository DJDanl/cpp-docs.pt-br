---
title: "Classe de IPropertyPageImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IPropertyPageImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Implementação de IPropertyPage ATL"
  - "Classe de IPropertyPageImpl"
  - "páginas de propriedades"
ms.assetid: f9b7c8b1-7a04-4eab-aa63-63efddb740fa
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPropertyPageImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IPropertyPageImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPropertyPageImpl`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPropertyPageImpl::IPropertyPageImpl](../Topic/IPropertyPageImpl::IPropertyPageImpl.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPropertyPageImpl::Activate](../Topic/IPropertyPageImpl::Activate.md)|Cria a janela da caixa de diálogo para a página de propriedades.|  
|[IPropertyPageImpl::Apply](../Topic/IPropertyPageImpl::Apply.md)|Aplica valores atuais da página de propriedades em objetos subjacentes especificados com `SetObjects`.  a implementação de ATL retorna `S_OK`.|  
|[IPropertyPageImpl::Deactivate](../Topic/IPropertyPageImpl::Deactivate.md)|A janela for criada com **Ativar**.|  
|[IPropertyPageImpl::GetPageInfo](../Topic/IPropertyPageImpl::GetPageInfo.md)|Recupera informações sobre a página de propriedades.|  
|[IPropertyPageImpl::Help](../Topic/IPropertyPageImpl::Help.md)|Chama o windows help para a página de propriedades.|  
|[IPropertyPageImpl::IsPageDirty](../Topic/IPropertyPageImpl::IsPageDirty.md)|Indica se a página de propriedades foi alterada desde que foi ativado.|  
|[IPropertyPageImpl::Move](../Topic/IPropertyPageImpl::Move.md)|As posições e redimensiona a caixa de diálogo da página de propriedades.|  
|[IPropertyPageImpl::SetDirty](../Topic/IPropertyPageImpl::SetDirty.md)|Sinaliza o estado da página de propriedades como modificado ou inalterado.|  
|[IPropertyPageImpl::SetObjects](../Topic/IPropertyPageImpl::SetObjects.md)|Fornece uma matriz de ponteiros de **IUnknown** para os objetos associados à página de propriedades.  Esses objetos recebem os valores atuais da página de propriedades com uma chamada a **Aplicar**.|  
|[IPropertyPageImpl::SetPageSite](../Topic/IPropertyPageImpl::SetPageSite.md)|Fornece a página de propriedades com um ponteiro de `IPropertyPageSite` , pelo qual a página de propriedades se comunica com o quadro da propriedade.|  
|[IPropertyPageImpl::Show](../Topic/IPropertyPageImpl::Show.md)|Torna a caixa de diálogo da página de propriedades visíveis ou invisível.|  
|[IPropertyPageImpl::TranslateAccelerator](../Topic/IPropertyPageImpl::TranslateAccelerator.md)|Processa um pressionamento de tecla especificado.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPropertyPageImpl::m\_bDirty](../Topic/IPropertyPageImpl::m_bDirty.md)|Especifica se o estado da página de propriedades é alterado.|  
|[IPropertyPageImpl::m\_dwDocString](../Topic/IPropertyPageImpl::m_dwDocString.md)|Armazena o identificador do recurso associado com a cadeia de caracteres de texto que descreve a página de propriedades.|  
|[IPropertyPageImpl::m\_dwHelpContext](../Topic/IPropertyPageImpl::m_dwHelpContext.md)|Armazena o identificador de contexto para o tópico da ajuda associado à página de propriedades.|  
|[IPropertyPageImpl::m\_dwHelpFile](../Topic/IPropertyPageImpl::m_dwHelpFile.md)|Armazena o identificador do recurso associado com o nome do arquivo de ajuda que descreve a página de propriedades.|  
|[IPropertyPageImpl::m\_dwTitle](../Topic/IPropertyPageImpl::m_dwTitle.md)|Armazena o identificador do recurso associado com a cadeia de caracteres de texto que aparece na guia para a página de propriedades.|  
|[IPropertyPageImpl::m\_nObjects](../Topic/IPropertyPageImpl::m_nObjects.md)|Armazena o número de objetos associados à página de propriedades.|  
|[IPropertyPageImpl::m\_pPageSite](../Topic/IPropertyPageImpl::m_pPageSite.md)|Pontos a interface de `IPropertyPageSite` através da página de propriedades se comunica com o quadro da propriedade.|  
|[IPropertyPageImpl::m\_ppUnk](../Topic/IPropertyPageImpl::m_ppUnk.md)|Aponta para uma matriz de ponteiros de **IUnknown** a objetos associados com a página de propriedades.|  
|[IPropertyPageImpl::m\_size](../Topic/IPropertyPageImpl::m_size.md)|Armazena a altura e largura da caixa de diálogo da página de propriedades, em pixels.|  
  
## Comentários  
 A interface de [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) permite que um objeto gerencia uma página de propriedades específico em uma folha de propriedades.  A classe `IPropertyPageImpl` fornece uma implementação padrão de esta interface e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IPropertyPage`  
  
 `IPropertyPageImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de IPropertyPage2Impl](../../atl/reference/ipropertypage2impl-class.md)   
 [Classe de IPerPropertyBrowsingImpl](../Topic/IPerPropertyBrowsingImpl%20Class.md)   
 [Classe de ISpecifyPropertyPagesImpl](../Topic/ISpecifyPropertyPagesImpl%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)