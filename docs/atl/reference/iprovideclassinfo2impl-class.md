---
title: "Classe de IProvideClassInfo2Impl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IProvideClassInfo2"
  - "ATL.IProvideClassInfo2Impl"
  - "IProvideClassInfo2Impl"
  - "ATL::IProvideClassInfo2Impl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "informações de classe, ATL"
  - "Implementação de IProvideClassInfo2 ATL"
  - "Classe de IProvideClassInfo2Impl"
ms.assetid: d74956e8-9c69-4cba-b99d-ca1ac031bb9d
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IProvideClassInfo2Impl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece uma implementação padrão dos métodos de [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) e de [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) .  
  
## Sintaxe  
  
```  
  
      template <  
   const CLSID* pcoclsid,  
   const IID* psrcid,  
   const GUID* plibid = &CAtlModule::m_libid,  
   WORD wMajor = 1,  
   WORD wMinor = 0,  
   class tihclass = CComTypeInfoHolder   
>  
class ATL_NO_VTABLE IProvideClassInfo2Impl :  
   public IProvideClassInfo2  
```  
  
#### Parâmetros  
 *pcoclsid*  
 Um ponteiro para o identificador de coclass.  
  
 *psrcid*  
 Um ponteiro para o identificador para o dispinterface de saída padrão de coclass.  
  
 `plibid`  
 Um ponteiro para o LIBID da biblioteca de tipos que contém informações sobre a interface.  Por padrão, a biblioteca de tipos no nível de servidor é passada.  
  
 `wMajor`  
 A versão principal de biblioteca de tipo.  o valor padrão é 1.  
  
 `wMinor`  
 A versão secundária de biblioteca de tipo.  o valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar informações do tipo de coclass.  o valor padrão é `CComTypeInfoHolder`.  
  
## Membros  
  
### Construtores  
  
|Nome|Descrição|  
|----------|---------------|  
|[IProvideClassInfo2Impl::IProvideClassInfo2Impl](../Topic/IProvideClassInfo2Impl::IProvideClassInfo2Impl.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IProvideClassInfo2Impl::GetClassInfo](../Topic/IProvideClassInfo2Impl::GetClassInfo.md)|Recupera um ponteiro de **ITypeInfo** a informações do tipo de coclass.|  
|[IProvideClassInfo2Impl::GetGUID](../Topic/IProvideClassInfo2Impl::GetGUID.md)|Recupera GUID para o dispinterface de saída do objeto.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IProvideClassInfo2Impl::\_tih](../Topic/IProvideClassInfo2Impl::_tih.md)|Gerencia informações de tipo para os coclass.|  
  
## Comentários  
 a interface de [IProvideClassInfo2](http://msdn.microsoft.com/library/windows/desktop/ms693764) estende [IProvideClassInfo](http://msdn.microsoft.com/library/windows/desktop/ms687303) adicionando o método de `GetGUID` .  Esse método permite que um cliente recupere a interface de saída IID de um objeto ao conjunto padrão de evento.  A classe `IProvideClassInfo2Impl` fornece uma implementação padrão dos métodos de **IProvideClassInfo** e de `IProvideClassInfo2` .  
  
 `IProvideClassInfo2Impl` contém um membro estático do tipo `CComTypeInfoHolder` que gerencia informações de tipo para os coclass.  
  
## Hierarquia de herança  
 `IProvideClassInfo2`  
  
 `IProvideClassInfo2Impl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)