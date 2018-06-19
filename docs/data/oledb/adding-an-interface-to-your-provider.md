---
title: Adicionando uma Interface ao provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB provider templates, object interfaces
ms.assetid: b0fc7cf8-428a-4584-9d64-ce9074d0eb66
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3d6bc5d1b6c47d2ffa26bffa98d47b930d6ed193
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33093540"
---
# <a name="adding-an-interface-to-your-provider"></a>Adicionando uma interface ao provedor
Determine qual objeto que você deseja adicionar a interface para (geralmente dados fonte, conjunto de linhas, comando ou sessão objetos criados pelo OLE DB Provider Assistente). É possível que o objeto que você precisa adicionar a interface é aquele que seu provedor não oferece suporte. Nesse caso, execute o ATL OLE DB Provider Assistente para criar o objeto. Clique com botão direito no projeto no modo de exibição de classe, clique em **Adicionar classe** do **adicionar** menu e clique **ATL OLE DB Provider**. Você talvez queira colocar o código de interface em um diretório separado e, em seguida, copiar os arquivos para o projeto de provedor.  
  
 Se você criou uma nova classe para oferecer suporte à interface, torne o objeto herdar dessa classe. Por exemplo, você pode adicionar a classe **IRowsetIndexImpl** para um objeto de conjunto de linhas:  
  
```cpp  
template <class Creator>  
class CAgentRowset :   
    public CRowsetImpl< CAgentRowset<Creator>, CAgentMan, Creator>,  
    public IRowsetIndexImpl< ... >   
```  
  
 Adicionar a interface para **COM_MAP** no objeto usando a macro COM_INTERFACE_ENTRY. Se não houver nenhum mapa, crie um. Por exemplo:  
  
```cpp  
BEGIN_COM_MAP(CAgentRowset)  
     COM_INTERFACE_ENTRY(IRowsetIndex)  
END_COM_MAP()  
```  
  
 Para o objeto de conjunto de linhas, a cadeia de mapa de seu pai do objeto para que o objeto pode delegar a classe pai. Neste exemplo, adicione a macro COM_INTERFACE_ENTRY_CHAIN ao mapa:  
  
```cpp  
BEGIN_COM_MAP(CAgentRowset)  
     COM_INTERFACE_ENTRY(IRowsetIndex)  
     COM_INTERFACE_ENTRY_CHAIN(CRowsetImpl)  
END_COM_MAP()  
```  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)