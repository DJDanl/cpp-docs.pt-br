---
title: Classe CArchiveException
ms.date: 11/04/2016
f1_keywords:
- CArchiveException
- AFX/CArchiveException
- AFX/CArchiveException::CArchiveException
- AFX/CArchiveException::m_cause
- AFX/CArchiveException::m_strFileName
helpviewer_keywords:
- CArchiveException [MFC], CArchiveException
- CArchiveException [MFC], m_cause
- CArchiveException [MFC], m_strFileName
ms.assetid: da31a127-e86c-41d1-b0b6-bed0865b1b49
ms.openlocfilehash: 68f64cfd7dc96da04fcc0945a6b996eab4101487
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231878"
---
# <a name="carchiveexception-class"></a>Classe CArchiveException

Representa uma condição de exceção de serialização

## <a name="syntax"></a>Sintaxe

```
class CArchiveException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchiveException::CArchiveException](#carchiveexception)|Constrói um objeto `CArchiveException`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CArchiveException:: m_cause](#m_cause)|Indica a causa da exceção.|
|[CArchiveException:: m_strFileName](#m_strfilename)|Especifica o nome do arquivo para esta condição de exceção.|

## <a name="remarks"></a>Comentários

A `CArchiveException` classe inclui um membro de dados públicos que indica a causa da exceção.

`CArchiveException`os objetos são construídos e lançados dentro de funções de membro [CArchive](../../mfc/reference/carchive-class.md) . Você pode acessar esses objetos dentro do escopo de uma expressão **Catch** . O código de causa é independente do sistema operacional. Para obter mais informações sobre o processamento de exceções, consulte [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CArchiveException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="carchiveexceptioncarchiveexception"></a><a name="carchiveexception"></a>CArchiveException::CArchiveException

Constrói um `CArchiveException` objeto, armazenando o valor de *causa* no objeto.

```
CArchiveException(
    int cause = CArchiveException::none,
    LPCTSTR lpszArchiveName = NULL);
```

### <a name="parameters"></a>parâmetros

*faz*<br/>
Uma variável de tipo enumerada que indica o motivo da exceção. Para obter uma lista dos enumeradores, consulte o membro de dados [m_cause](#m_cause) .

*lpszArchiveName*<br/>
Aponta para uma cadeia de caracteres que contém o nome do `CArchive` objeto que está causando a exceção.

### <a name="remarks"></a>Comentários

Você pode criar um `CArchiveException` objeto no heap e jogá-lo por conta própria ou deixar que a função global [AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception) tratá-lo para você.

Não use esse construtor diretamente; em vez disso, chame a função global `AfxThrowArchiveException` .

## <a name="carchiveexceptionm_cause"></a><a name="m_cause"></a>CArchiveException:: m_cause

Especifica a causa da exceção.

```
int m_cause;
```

### <a name="remarks"></a>Comentários

Esse membro de dados é uma variável pública do tipo **`int`** . Seus valores são definidos por um `CArchiveException` tipo enumerado. Os enumeradores e seus significados são os seguintes:

- `CArchiveException::none`Não ocorreu nenhum erro.

- `CArchiveException::genericException`Erro não especificado.

- `CArchiveException::readOnly`Tentativa de gravar em um arquivo morto aberto para carregamento.

- `CArchiveException::endOfFile`Fim do arquivo atingido ao ler um objeto.

- `CArchiveException::writeOnly`Tentativa de ler de um arquivo morto aberto para armazenamento.

- `CArchiveException::badIndex`Formato de arquivo inválido.

- `CArchiveException::badClass`Tentativa de ler um objeto em um objeto do tipo incorreto.

- `CArchiveException::badSchema`Tentativa de ler um objeto com uma versão diferente da classe.

    > [!NOTE]
    >  Esses enumeradores de causa de `CArchiveException` são diferentes dos enumeradores de causa de `CFileException`.

    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em vez disso. Se **genérico** for usado em um aplicativo e criado com/CLR, haverá erros de sintaxe que não são fáceis de decifrar.

## <a name="carchiveexceptionm_strfilename"></a><a name="m_strfilename"></a>CArchiveException:: m_strFileName

Especifica o nome do arquivo para esta condição de exceção.

```
CString m_strFileName;
```

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CArchive](../../mfc/reference/carchive-class.md)<br/>
[AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception)<br/>
[Processamento de exceção](../../mfc/reference/exception-processing.md)
