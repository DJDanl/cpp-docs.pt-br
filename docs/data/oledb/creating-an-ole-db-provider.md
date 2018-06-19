---
title: Criando um provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: f73017c3-c89f-41a6-a306-ea992cf6092c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f649b5b4c79c4148d0aed026b044485ca2b1eaa7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33097101"
---
# <a name="creating-an-ole-db-provider"></a>Criando um provedor de banco de dados OLE
A maneira recomendada para criar um provedor OLE DB é usar os assistentes para criar um projeto COM ATL e um provedor e, em seguida, modifique os arquivos usando os modelos OLE DB. Como personalizar o seu provedor, você pode comentar propriedades indesejadas e adicione a interfaces opcionais.  
  
 As etapas básicas são as seguintes:  
  
1.  Use o Assistente de projeto de ATL para criar os arquivos de projeto básico e ATL OLE DB Provider Assistente para criar o provedor (selecione **ATL OLE DB Provider** na pasta Visual C++ **Adicionar classe**).  
  
2.  Modifique o código de `Execute` método CMyProviderRS.h. Para obter um exemplo, consulte [lendo cadeias de caracteres em um provedor OLE DB](../../data/oledb/reading-strings-into-the-ole-db-provider.md).  
  
3.  Edite os mapeamentos de propriedade em myproviderds. H, myprovidersess. H e myproviderrs. H. O assistente cria mapas de propriedade que contêm todas as propriedades de um provedor pode implementar. Percorrer os mapas de propriedade e remova ou comente propriedades que seu provedor não precisa oferecer suporte.  
  
4.  Atualize o PROVIDER_COLUMN_MAP, que pode ser encontrado em myproviderrs. H. Para obter um exemplo, consulte [armazenar cadeias de caracteres no provedor OLE DB](../../data/oledb/storing-strings-in-the-ole-db-provider.md).  
  
5.  Quando você estiver pronto para testar seu provedor, você pode testá-lo ao tentar localizar o provedor em uma enumeração do provedor. Para obter exemplos de código de teste que localiza um provedor em uma enumeração, consulte o [CATDB](http://msdn.microsoft.com/en-us/003d516b-2bf6-444e-8be5-4ebaa0b66046) e [DBVIEWER](http://msdn.microsoft.com/en-us/07620f99-c347-4d09-9ebc-2459e8049832) exemplos ou exemplo [consumidor simples A implementação de](../../data/oledb/implementing-a-simple-consumer.md).  
  
6.  Adicione quaisquer interfaces adicionais que você deseja. Para obter um exemplo, consulte [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).  
  
    > [!NOTE]
    >  Por padrão, os assistentes de geram código que é o nível de banco de dados OLE 0 compatíveis. Para garantir que seu aplicativo permaneça nível 0 compatível, não remova qualquer uma das interfaces geradas pelo Assistente do código.  
  
## <a name="see-also"></a>Consulte também  
 [CATDB](http://msdn.microsoft.com/en-us/003d516b-2bf6-444e-8be5-4ebaa0b66046)   
 [DBVIEWER](http://msdn.microsoft.com/en-us/07620f99-c347-4d09-9ebc-2459e8049832)