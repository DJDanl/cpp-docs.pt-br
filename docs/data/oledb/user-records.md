---
title: "Registros de usuário | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: COLUMN_ENTRY_MAP
dev_langs: C++
helpviewer_keywords:
- rowsets [C++], accessors
- COLUMN_ENTRY macro
- COLUMN_ENTRY_MAP macro
- user records, OLE DB consumer templates
- OLE DB consumer templates, user records
- CAccessor class, example
- BEGIN_ACCESSOR_MAP macro
- accessors [C++], rowsets
- accessors [C++], static
- BEGIN_ACCESSOR macro, example
ms.assetid: 2de9e5eb-53ce-42b1-80fa-57d46600a80c
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8db24d5162aba3ba5f0f1e01b3b1da9c8d6ab99f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="user-records"></a>Registros de usuário
Para usar um acessador estático (ou seja, um acessador é derivado de **CAccessor)**, o consumidor deve ter um registro de usuário. O registro do usuário é uma classe do C++ que contém elementos de dados para o identificador de entrada ou saída. Assistente de ATL OLE DB consumidor gera um registro de usuário para o consumidor. Você pode adicionar métodos para o registro do usuário para tarefas opcionais, como o tratamento de comandos.  
  
 O código a seguir mostra um registro de exemplo que controla os comandos. No registro de usuário, `BEGIN_COLUMN_MAP` representa um conjunto de linhas de dados passado para o consumidor de um provedor. `BEGIN_PARAM_MAP`representa um conjunto de parâmetros de comando. Este exemplo usa um [CCommand](../../data/oledb/ccommand-class.md) classe para lidar com os parâmetros de comando. Os membros de dados nas entradas de mapa representam deslocamentos em um bloco contíguo de memória para cada instância da classe. O `COLUMN_ENTRY` macros correspondem do `PROVIDER_COLUMN_ENTRY` macros no lado do provedor.  
  
 Para obter mais informações sobre o **COLUMN_MAP** e **PARAM_MAP** macros, consulte [Macros para modelos OLE DB consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).  
  
```  
class CArtists  
{  
public:  
// Data Elements  
   CHAR m_szFirstName[20];  
   CHAR m_szLastName[30];  
   short m_nAge;  
  
// Column binding map  
BEGIN_COLUMN_MAP(CArtists)  
   COLUMN_ENTRY(1, m_szFirstName)  
   COLUMN_ENTRY(2, m_szLastName)  
   COLUMN_ENTRY(3, m_nAge)  
END_COLUMN_MAP()  
  
// Parameter binding map  
BEGIN_PARAM_MAP(CArtists)  
   COLUMN_ENTRY(1, m_nAge)  
END_PARAM_MAP()  
};  
```  
  
## <a name="wizard-generated-user-records"></a>Registros de usuário gerado pelo Assistente  
 Se você usar o Assistente de ATL OLE DB consumidor para gerar um consumidor, você tem a opção de usar modelos OLE DB ou OLE DB atributos. O código gerado é diferente em cada caso. Para obter mais informações sobre esse código, consulte [Consumer Wizard-Generated Classes](../../data/oledb/consumer-wizard-generated-classes.md).  
  
## <a name="user-record-support-for-multiple-accessors"></a>Suporte ao registro de usuário para vários acessadores  
 Para obter uma discussão detalhada dos cenários em que você precisa usar vários acessadores, consulte [usando vários acessadores em um conjunto de linhas](../../data/oledb/using-multiple-accessors-on-a-rowset.md).  
  
 O exemplo a seguir mostra o registro de usuário modificado para dar suporte a vários acessadores no conjunto de linhas. Em vez de `BEGIN_COLUMN_MAP` e `END_COLUMN_MAP`, ele usa [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md) e [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) cada acessador. O `BEGIN_ACCESSOR` macro Especifica o número de acessador (deslocamento de zero) e se o acessador é uma autoaccessor. Chamada de Autoaccessors `GetData` para recuperar dados automaticamente em uma chamada para [MoveNext](../../data/oledb/crowset-movenext.md). Acessadores nonautomatic exigem que você explicitamente recuperar os dados. Use um acessador nonautomatic se você estiver associando a um campo de dados grandes (como uma imagem de bitmap) que não deseja recuperar para cada registro.  
  
```  
class CMultiArtists  
{  
public:  
// Data Elements  
   CHAR m_szFirstName[20];  
   CHAR m_szLastName[30];  
   short m_nAge;  
  
// Column binding map  
BEGIN_ACCESSOR_MAP(CMultiArtists, 2)  
   BEGIN_ACCESSOR(0, true)    // true specifies an auto accessor  
    COLUMN_ENTRY(1, m_szFirstName)  
    COLUMN_ENTRY(2, m_szLastName)  
   END_ACCESSOR()  
   BEGIN_ACCESSOR(1, false)   // false specifies a manual accessor  
    COLUMN_ENTRY(3, m_nAge)  
   END_ACCESSOR()  
END_ACCESSOR_MAP()  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)