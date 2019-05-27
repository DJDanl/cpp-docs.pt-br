---
title: Registros de usuário
ms.date: 05/09/2019
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
ms.openlocfilehash: c9c1126f0e8248f31ac739bb1d939f811bda678d
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65525280"
---
# <a name="user-records"></a>Registros de usuário

> [!NOTE]
> O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](creating-a-consumer-without-using-a-wizard.md).

Para usar um acessador estático (ou seja, um acessador derivado de `CAccessor`), o consumidor deve ter um registro de usuário. O registro de usuário é uma classe C++ que contém os elementos de dados para manipular a entrada ou a saída. O **Assistente de Consumidor OLE DB da ATL** gera um registro de usuário para seu consumidor. Você pode adicionar métodos ao registro do usuário para tarefas opcionais, como manipulação de comandos.

O código a seguir mostra um registro de exemplo que manipula os comandos. No registro de usuário, BEGIN_COLUMN_MAP representa um conjunto de linhas de dados passado de um provedor para o consumidor. BEGIN_PARAM_MAP representa um conjunto de parâmetros de comando. Este exemplo usa uma classe [CCommand](../../data/oledb/ccommand-class.md) para manipular os parâmetros de comando. Os membros de dados nas entradas do mapa representam deslocamentos em um bloco contíguo de memória para cada instância da classe. As macros COLUMN_ENTRY correspondem às macros PROVIDER_COLUMN_ENTRY no lado do provedor.

Saiba mais sobre as macros COLUMN_MAP e PARAM_MAP em [Macros para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md).

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

## <a name="wizard-generated-user-records"></a>Registros de usuário gerados pelo assistente

Usando o **Assistente de Consumidor OLE DB da ATL** para gerar um consumidor, você tem a opção de usar modelos ou atributos OLE DB. O código gerado é diferente em cada caso. Saiba mais sobre esse código em [Classes geradas pelo assistente do consumidor](../../data/oledb/consumer-wizard-generated-classes.md).

## <a name="user-record-support-for-multiple-accessors"></a>Suporte ao registro de usuário para vários acessadores

Confira uma discussão detalhada dos cenários nos quais você precisa usar vários acessadores em [Uso de vários acessadores em um conjunto de linhas](../../data/oledb/using-multiple-accessors-on-a-rowset.md).

O exemplo a seguir mostra o registro de usuário modificado para ser compatível com vários acessadores no conjunto de linhas. Em vez de BEGIN_COLUMN_MAP e END_COLUMN_MAP, ele usa [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md) e [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) para cada acessador. A macro BEGIN_ACCESSOR especifica o número do acessador (deslocamento a partir de zero) e se o acessador é automático. Os acessadores automáticos chamam `GetData` para recuperar dados automaticamente em um chamada a [MoveNext](../../data/oledb/crowset-movenext.md). Os acessadores não automáticos exigem que você recupere os dados explicitamente. Use um acessador não automático se estiver fazendo a associação a um campo de dados grande (como uma imagem de bitmap) que você pode não querer recuperar para cada registro.

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

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)