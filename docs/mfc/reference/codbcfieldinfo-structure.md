---
title: Estrutura CODBCFieldInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CODBCFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- ODBC [MFC], data source information
- CODBCFieldInfo structure [MFC]
ms.assetid: 92598b4f-facc-4108-b282-63a179ff79ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5f178791bdaf57e5678f2e30d8994c2ffd140ffc
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055791"
---
# <a name="codbcfieldinfo-structure"></a>Estrutura CODBCFieldInfo

O `CODBCFieldInfo` estrutura contém informações sobre os campos em uma fonte de dados ODBC.

## <a name="syntax"></a>Sintaxe

```
struct CODBCFieldInfo
{
    CString m_strName;
    SWORD m_nSQLType;
    UDWORD m_nPrecision;
    SWORD m_nScale;
    SWORD m_nNullability;
};
```

#### <a name="parameters"></a>Parâmetros

*m_strName*<br/>
O nome do campo.

*m_nSQLType*<br/>
O tipo de dados SQL do campo. Isso pode ser um tipo de dados SQL ODBC ou um tipo de dados SQL específica do driver. Para obter uma lista dos tipos de dados SQL ODBC válidos, consulte "Tipos de dados SQL" no SDK do Windows. Para obter informações sobre tipos de dados SQL específico do driver, consulte a documentação do driver.

*m_nPrecision*<br/>
A precisão máxima do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" no SDK do Windows.

*m_nScale*<br/>
A escala do campo. Para obter detalhes, consulte "Precisão, escala, comprimento e tamanho de exibição" no SDK do Windows.

*m_nNullability*<br/>
Se o campo aceita um valor Null. Isso pode ser um dos dois valores: SQL_NULLABLE se o campo aceita valores nulos, SQL_NO_NULLS se o campo não aceita valores nulos ou.

## <a name="remarks"></a>Comentários

Para recuperar essas informações, chame [CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CRecordset::GetODBCFieldInfo](../../mfc/reference/crecordset-class.md#getodbcfieldinfo)<br/>
[CRecordset::GetFieldValue](../../mfc/reference/crecordset-class.md#getfieldvalue)

