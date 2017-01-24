---
title: "Classe de IDataObjectImpl | Microsoft Docs"
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
  - "IDataObjectImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "transferência de dados [C++]"
  - "transferência de dados [C++], Transferência de dados uniforme"
  - "IDataObject, Implementação de ATL"
  - "Classe de IDataObjectImpl"
ms.assetid: b680f0f7-7795-40a1-a0f6-f48768201c89
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IDataObjectImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para oferecer suporte a transferência de dados uniforme e gerenciar conexões.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IDataObjectImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IDataObjectImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDataObjectImpl::DAdvise](../Topic/IDataObjectImpl::DAdvise.md)|Estabelece uma conexão entre o objeto de dados e um. coletor de conselhos  Isso permite que o coletor de conselhos receber notificações de alterações para o objeto.|  
|[IDataObjectImpl::DUnadvise](../Topic/IDataObjectImpl::DUnadvise.md)|Finaliza estabelecida uma conexão com `DAdvise`anteriormente.|  
|[IDataObjectImpl::EnumDAdvise](../Topic/IDataObjectImpl::EnumDAdvise.md)|Cria um enumerador para iterar através de conexões consultivas atual.|  
|[IDataObjectImpl::EnumFormatEtc](../Topic/IDataObjectImpl::EnumFormatEtc.md)|Cria um enumerador para iterar através das estruturas de **FORMATETC** suportadas pelo objeto de dados.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IDataObjectImpl::FireDataChange](../Topic/IDataObjectImpl::FireDataChange.md)|Envia uma notificação de alteração de volta para cada recomendam o coletor.|  
|[IDataObjectImpl::GetCanonicalFormatEtc](../Topic/IDataObjectImpl::GetCanonicalFormatEtc.md)|Recupera uma estrutura de **FORMATETC** logicamente equivalente a uma que é mais complexa.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IDataObjectImpl::GetData](../Topic/IDataObjectImpl::GetData.md)|Transfere dados de objeto de dados para o cliente.  Os dados são descritos em uma estrutura de **FORMATETC** e transferidos por meio de uma estrutura de **STGMEDIUM** .|  
|[IDataObjectImpl::GetDataHere](../Topic/IDataObjectImpl::GetDataHere.md)|Semelhante a `GetData`, a não ser que o cliente deve atribuir a estrutura de **STGMEDIUM** .  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IDataObjectImpl::QueryGetData](../Topic/IDataObjectImpl::QueryGetData.md)|Determina se o objeto de dados suporta uma estrutura específica de **FORMATETC** para transferir dados.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IDataObjectImpl::SetData](../Topic/IDataObjectImpl::SetData.md)|Transfere dados do cliente para o objeto de dados.  a implementação de ATL retorna **E\_NOTIMPL**.|  
  
## Comentários  
 A interface de [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) fornece métodos para a transferência de dados de uniforme de suporte.  `IDataObject` usa as estruturas [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) e [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) de formato padrão para armazenar e recuperar dados.  
  
 `IDataObject` também gerencia para manipular conexões recomendar dissipadores notificações de alteração de dados.  Para que o cliente receber dados alterar notificações do objeto de dados, o cliente deve implementar a interface de [IAdviseSink](http://msdn.microsoft.com/library/windows/desktop/ms692513) em um objeto chamado. um coletor de conselhos  Quando o cliente chama **IDataObject::DAdvise**em seguida, é estabelecida uma conexão entre o objeto de dados e o coletor. de conselhos  
  
 A classe `IDataObjectImpl` fornece uma implementação padrão de `IDataObject` e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IDataObject`  
  
 `IDataObjectImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)