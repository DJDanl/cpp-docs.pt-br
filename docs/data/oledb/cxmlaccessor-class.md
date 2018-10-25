---
title: Classe CXMLAccessor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::CXMLAccessor
- CXMLAccessor
- ATL.CXMLAccessor
- ATL.CXMLAccessor.GetXMLColumnData
- CXMLAccessor::GetXMLColumnData
- CXMLAccessor.GetXMLColumnData
- ATL::CXMLAccessor::GetXMLColumnData
- GetXMLColumnData
- ATL::CXMLAccessor::GetXMLRowData
- ATL.CXMLAccessor.GetXMLRowData
- CXMLAccessor::GetXMLRowData
- CXMLAccessor.GetXMLRowData
- GetXMLRowData
dev_langs:
- C++
helpviewer_keywords:
- CXMLAccessor class
- GetXMLColumnData method
- GetXMLRowData method
ms.assetid: c88c082c-ec2f-4351-8947-a330b15e448a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 71922df2b4d94d06b21ade32b4d8c4ca22fa50c8
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065415"
---
# <a name="cxmlaccessor-class"></a>Classe CXMLAccessor

Permite que você acessar fontes de dados como dados de cadeia de caracteres quando você não possui conhecimento do esquema do repositório de dados (estrutura subjacente).

## <a name="syntax"></a>Sintaxe

```cpp
class CXMLAccessor : public CDynamicStringAccessorW
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[GetXMLColumnData](#getxmlcolumndata)|Recupera as informações de coluna.|
|[GetXMLRowData](#getxmlrowdata)|Recupera todo o conteúdo de uma tabela por linhas.|

## <a name="remarks"></a>Comentários

No entanto, `CXMLAccessor` difere `CDynamicStringAccessorW` em que ele converte todos os dados acessados do armazenamento de dados como XML formatado (marcados) dados. Isso é especialmente útil para a saída para páginas de Web com suporte a XML. Os nomes de marca XML corresponderá a nomes de coluna do repositório de dados mais próximo possível.

Use `CDynamicAccessor` métodos para obter informações de coluna. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução.

As informações de coluna são armazenadas em um buffer criadas e gerenciadas por esta classe. Obter informações de coluna usando [GetXMLColumnData](#getxmlcolumndata) ou obter dados de coluna por linhas usando [GetXMLRowData](#getxmlrowdata).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_OLEDB_Consumer#14](../../data/oledb/codesnippet/cpp/cxmlaccessor-class_1.cpp)]

## <a name="getxmlcolumndata"></a> Cxmlaccessor:: Getxmlcolumndata

Recupera as informações de tipo de coluna de uma tabela como dados de cadeia de caracteres formatada em XML, por coluna.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetXMLColumnData(CSimpleStringW& strOutput) throw();
```

#### <a name="parameters"></a>Parâmetros

*strOutput*<br/>
[out] Uma referência para um buffer de cadeia de caracteres que contém as informações de tipo de coluna a ser recuperado. A cadeia de caracteres é formatada com nomes de marca XML que correspondem aos nomes de coluna do repositório de dados.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

O exemplo a seguir mostra como as informações de tipo de coluna são formatadas em XML. `type` Especifica o tipo de dados da coluna. Observe que os tipos de dados são baseados em tipos de dados OLE DB, não aquelas do banco de dados que está sendo acessado.

`<columninfo>`

`<column type = I2/> ColumnName`

`</columninfo>`

## <a name="getxmlrowdata"></a> Cxmlaccessor:: Getxmlrowdata

Recupera todo o conteúdo de uma tabela como dados de cadeia de caracteres formatada em XML, por linha.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetXMLRowData(CSimpleStringW& strOutput, 
   bool bAppend = false) throw();
```

#### <a name="parameters"></a>Parâmetros

*strOutput*<br/>
[out] Uma referência a um buffer que contém os dados da tabela a ser recuperado. Os dados são formatados como dados de cadeia de caracteres com os nomes de marca XML que correspondem aos nomes de coluna do repositório de dados.

*bAppend*<br/>
[in] Um valor booliano que especifica se deve acrescentar uma cadeia de caracteres ao final dos dados de saída.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

O exemplo a seguir mostra como os dados da linha são formatados em XML. `DATA` abaixo representa os dados da linha. Use mover métodos para mover para a linha desejada.

`<row>`

`<column name>DATA</column name>`

`</row>`

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)<br/>
[Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)<br/>
[Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)