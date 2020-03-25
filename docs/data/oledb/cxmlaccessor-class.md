---
title: Classe CXMLAccessor
ms.date: 11/04/2016
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
helpviewer_keywords:
- CXMLAccessor class
- GetXMLColumnData method
- GetXMLRowData method
ms.assetid: c88c082c-ec2f-4351-8947-a330b15e448a
ms.openlocfilehash: f25fb3635f70ee9a0e38ddcdbcf373fe6b1b84c8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211036"
---
# <a name="cxmlaccessor-class"></a>Classe CXMLAccessor

Permite que você acesse fontes de dados como dados de cadeia de caracteres quando você não tem conhecimento do esquema do repositório de dados (estrutura subjacente).

## <a name="syntax"></a>Sintaxe

```cpp
class CXMLAccessor : public CDynamicStringAccessorW
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[GetXMLColumnData](#getxmlcolumndata)|Recupera as informações da coluna.|
|[GetXMLRowData](#getxmlrowdata)|Recupera todo o conteúdo de uma tabela por linhas.|

## <a name="remarks"></a>Comentários

No entanto, `CXMLAccessor` difere de `CDynamicStringAccessorW`, pois converte todos os dados acessados do armazenamento de dados como dados formatados em XML (marcados). Isso é especialmente útil para a saída para páginas da Web com reconhecimento XML. Os nomes de marca XML corresponderão aos nomes de coluna do repositório de dados o mais próximo possível.

Use os métodos `CDynamicAccessor` para obter informações de coluna. Use essas informações de coluna para criar um acessador dinamicamente em tempo de execução.

As informações de coluna são armazenadas em um buffer criado e gerenciado por essa classe. Obtenha informações de coluna usando [GetXMLColumnData](#getxmlcolumndata) ou obtenha dados de coluna por linhas usando [GetXMLRowData](#getxmlrowdata).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_OLEDB_Consumer#14](../../data/oledb/codesnippet/cpp/cxmlaccessor-class_1.cpp)]

## <a name="cxmlaccessorgetxmlcolumndata"></a><a name="getxmlcolumndata"></a>CXMLAccessor::GetXMLColumnData

Recupera as informações de tipo de coluna de uma tabela como dados de cadeia de caracteres formatados em XML, por coluna.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetXMLColumnData(CSimpleStringW& strOutput) throw();
```

#### <a name="parameters"></a>parâmetros

*strOutput*<br/>
fora Uma referência a um buffer de cadeia de caracteres que contém as informações de tipo de coluna a serem recuperadas. A cadeia de caracteres é formatada com nomes de marca XML que correspondem aos nomes de coluna do repositório de dados.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

O seguinte mostra como as informações de tipo de coluna são formatadas em XML. `type` especifica o tipo de dados da coluna. Observe que os tipos de dados são baseados em OLE DB tipos de dados, não os que estão sendo acessados.

`<columninfo>`

`<column type = I2/> ColumnName`

`</columninfo>`

## <a name="cxmlaccessorgetxmlrowdata"></a><a name="getxmlrowdata"></a>CXMLAccessor::GetXMLRowData

Recupera todo o conteúdo de uma tabela como dados de cadeia de caracteres formatados em XML, por linha.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetXMLRowData(CSimpleStringW& strOutput,
   bool bAppend = false) throw();
```

#### <a name="parameters"></a>parâmetros

*strOutput*<br/>
fora Uma referência a um buffer que contém os dados da tabela a serem recuperados. Os dados são formatados como dados de cadeia de caracteres com nomes de marca XML que correspondem aos nomes de coluna do repositório de dados.

*bAppend*<br/>
no Um valor booliano que especifica se uma cadeia de caracteres deve ser acrescentada ao final dos dados de saída.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

O seguinte mostra como os dados de linha são formatados em XML. `DATA` abaixo representa os dados da linha. Use os métodos move para mover para a linha desejada.

`<row>`

`<column name>DATA</column name>`

`</row>`

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)<br/>
[Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)<br/>
[Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)
