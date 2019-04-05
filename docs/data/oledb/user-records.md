---
title: Registros de usuário
ms.date: 10/22/2018
f1_keywords:
- COLUMN_ENTRY_MAP
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
ms.openlocfilehash: 5dd7be3eccd59dc1a5a0dc1cd6932ca1310627c0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041001"
---
# <a name="user-records"></a>Registros de usuário

Para usar um acessador estática (ou seja, um acessador é derivada de `CAccessor`), o consumidor deve ter um registro de usuário. O registro do usuário é uma classe C++ que contém os elementos de dados para o identificador de entrada ou saída. O **ATL OLE DB Assistente de consumidor** gera um registro de usuário para que o consumidor. Você pode adicionar métodos para o registro do usuário para tarefas opcionais, como tratamento de comandos.

O código a seguir mostra um registro de exemplo que manipula os comandos. No registro de usuário, BEGIN_COLUMN_MAP representa um conjunto de linhas de dados passado para o consumidor de um provedor. BEGIN_PARAM_MAP representa um conjunto de parâmetros de comando. Este exemplo usa uma [CCommand](../../data/oledb/ccommand-class.md) classe para lidar com os parâmetros de comando. Os membros de dados nas entradas de mapa representam deslocamentos em um bloco contíguo de memória para cada instância da classe. As macros COLUMN_ENTRY correspondem às macros PROVIDER_COLUMN_ENTRY no lado do provedor.

Para obter mais informações sobre as macros COLUMN_MAP e PARAM_MAP, consulte [Macros para OLE DB modelos de consumidor](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).

```cpp
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

Se você usar o **ATL OLE DB Assistente de consumidor** para gerar um consumidor, você tem a opção de usar modelos OLE DB ou atributos do OLE DB. O código gerado é diferente em cada caso. Para obter mais informações sobre esse código, consulte [Consumer Wizard-Generated Classes](../../data/oledb/consumer-wizard-generated-classes.md).

## <a name="user-record-support-for-multiple-accessors"></a>Suporte ao registro de usuário para vários acessadores

Para obter uma discussão detalhada sobre os cenários em que você precisa usar vários acessadores, consulte [usando vários acessadores em um conjunto de linhas](../../data/oledb/using-multiple-accessors-on-a-rowset.md).

O exemplo a seguir mostra o registro de usuário modificado para dar suporte a vários acessadores em um conjunto de linhas. Em vez de BEGIN_COLUMN_MAP e END_COLUMN_MAP, ele usa [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md) e [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) cada acessador. A macro BEGIN_ACCESSOR Especifica o número de acessador (deslocamento de zero) e se o acessador é uma autoaccessor. Chamada de Autoaccessors `GetData` para recuperar os dados automaticamente em uma chamada para [MoveNext](../../data/oledb/crowset-movenext.md). Acessadores nonautomatic exigem que você explicitamente recuperar os dados. Use um acessador nonautomatic se você estiver associando a um campo de dados grandes (como uma imagem de bitmap) que você talvez não queira recuperar para cada registro.

```cpp
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

[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)