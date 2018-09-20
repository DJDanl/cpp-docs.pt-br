---
title: Estrutura CDaoRelationInfo | Microsoft Docs
ms.custom: ''
ms.date: 06/25/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoRelationInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Relations collection
- CDaoRelationInfo structure [MFC]
ms.assetid: 92dda090-fe72-4090-84ec-429498a48aad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5ca5fceb25fdc9640248e0e510efb0c2f18eb506
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380081"
---
# <a name="cdaorelationinfo-structure"></a>Estrutura CDaoRelationInfo

O `CDaoRelationInfo` estrutura contém informações sobre uma relação definida entre os campos de duas tabelas em um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.

## <a name="syntax"></a>Sintaxe

```cpp
struct CDaoRelationInfo
{
    CDaoRelationInfo();                     // Constructor
    CString m_strName;                      // Primary
    CString m_strTable;                     // Primary
    CString m_strForeignTable;              // Primary
    long m_lAttributes;                     // Secondary
    CDaoRelationFieldInfo* m_pFieldInfos;   // Secondary
    short m_nFields;                        // Secondary
    // Below the // Implementation comment:
    // Destructor, not otherwise documented
};
```

#### <a name="parameters"></a>Parâmetros

*m_strName*<br/>
Exclusivamente nomeia o objeto de relação. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

*m_strTable*<br/>
Nomeia a tabela primária da relação.

*m_strForeignTable*<br/>
Nomes de tabela externa na relação. Uma tabela externa é uma tabela usada para conter chaves estrangeiras. Em geral, você deve usar uma tabela externa para estabelecer ou impor a integridade referencial. A tabela externa normalmente está no lado muitos de uma relação um-para-muitos. Exemplos de tabelas externas incluem tabelas que contêm códigos para o American estados ou províncias canadenses ou pedidos de clientes.

*m_lAttributes*<br/>
Contém informações sobre o tipo de relação. O valor desse membro pode ser qualquer um dos seguintes:

- `dbRelationUnique` Relação é-para-um.

- `dbRelationDontEnforce` Relação não é imposta (não há integridade referencial).

- `dbRelationInherited` Existe uma relação em um banco de dados não atual que contém as duas tabelas anexadas.

- `dbRelationLeft` A relação é uma associação à esquerda. Uma junção externa esquerda inclui todos os registros da primeira (esquerda) de duas tabelas, mesmo se não existem valores correspondentes para registros da segunda tabela (direita).

- `dbRelationRight` A relação é a junção à direita. Uma junção externa direita inclui todos os registros da segunda (direita) de duas tabelas, mesmo se não existem valores correspondentes para os registros na primeira tabela (esquerda).

- `dbRelationUpdateCascade` As atualizações ocorrerão em cascata.

- `dbRelationDeleteCascade` Exclusões ocorrerão em cascata.

*m_pFieldInfos*<br/>
Um ponteiro para uma matriz de [CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md) estruturas. A matriz contém um objeto para cada campo na relação. O `m_nFields` membro de dados fornece uma contagem dos elementos da matriz.

*m_nFields*<br/>
O número de `CDaoRelationFieldInfo` objetos no `m_pFieldInfos` membro de dados.

## <a name="remarks"></a>Comentários

As referências a primária e secundária acima indicam como as informações são retornadas pela [GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) função de membro na classe `CDaoDatabase`.

Objetos de relação não são representados por uma classe do MFC. Em vez disso, o objeto DAO subjacente de um objeto MFC do `CDaoDatabase` classe mantém uma coleção de objetos de relação: `CDaoDatabase` fontes de funções de membro para acessar alguns itens individuais de informações de relação, ou você podem acessá-los todos de uma vez com um `CDaoRelationInfo` objeto chamando o `GetRelationInfo` a função de membro do objeto recipiente do banco de dados.

As informações recuperadas pelo [CDaoDatabase::GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) função de membro é armazenada em um `CDaoRelationInfo` estrutura. `CDaoRelationInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoRelationInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estrutura CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md)
