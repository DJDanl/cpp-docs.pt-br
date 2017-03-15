---
title: "Adicionando uma interface ao provedor | Microsoft Docs"
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
  - "modelos de provedor do OLE DB, Interfaces de objeto"
ms.assetid: b0fc7cf8-428a-4584-9d64-ce9074d0eb66
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma interface ao provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determine objeto que você deseja adicionar a interface \(normalmente fonte de dados, conjunto de linhas, comando, ou objetos de sessão criados pelo assistente do provedor OLE DB\).  É possível que o objeto que você precisa adicionar a interface é uma que o provedor não oferecer suporte a.  Nesse caso, execute o assistente do provedor OLE DB de ATL para criar o objeto.  Clique com o botão direito do mouse na exibição da classe **Adicionar Classe** , clique no menu de **Adicionar** , e clique em **ATL OLE DB Provider**.  Talvez você queira colocar o código de interface em um diretório separado e para copiar os arquivos em seu provedor do projeto.  
  
 Se você criou uma nova classe para dar suporte à interface, faça o objeto ser herdada da classe.  Por exemplo, você pode adicionar a classe **IRowsetIndexImpl** a um objeto de conjunto de linhas:  
  
```  
template <class Creator>  
class CAgentRowset :   
public CRowsetImpl< CAgentRowset<Creator>, CAgentMan, Creator>,  
   public IRowsetIndexImpl< ... >   
```  
  
 Adicionar à interface **COM\_MAP** no objeto usando a macro de COM\_INTERFACE\_ENTRY.  Se não houver nenhum mapa, crie um.  Por exemplo:  
  
```  
BEGIN_COM_MAP(CAgentRowset)  
     COM_INTERFACE_ENTRY(IRowsetIndex)  
END_COM_MAP()  
```  
  
 Para o objeto de conjunto de linhas, o encadeamento o mapa do seu objeto pai de forma que o objeto pode delegar a classe pai.  Neste exemplo, adicione a macro de COM\_INTERFACE\_ENTRY\_CHAIN ao mapa:  
  
```  
BEGIN_COM_MAP(CAgentRowset)  
     COM_INTERFACE_ENTRY(IRowsetIndex)  
     COM_INTERFACE_ENTRY_CHAIN(CRowsetImpl)  
END_COM_MAP()  
```  
  
## Consulte também  
 [Trabalhando com modelos de provedor de banco de dados OLE](../../data/oledb/working-with-ole-db-provider-templates.md)