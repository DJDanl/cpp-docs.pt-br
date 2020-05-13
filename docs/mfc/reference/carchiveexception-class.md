---
title: CArchiveClasse de exceção
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
ms.openlocfilehash: ad2a9d8c5b4466a04b5a88fcce7679911bf1b81a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377009"
---
# <a name="carchiveexception-class"></a>CArchiveClasse de exceção

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
|[CArchiveException::m_cause](#m_cause)|Indica a causa da exceção.|
|[CArchiveException::m_strFileName](#m_strfilename)|Especifica o nome do arquivo para esta condição de exceção.|

## <a name="remarks"></a>Comentários

A `CArchiveException` classe inclui um membro de dados públicos que indica a causa da exceção.

`CArchiveException`objetos são construídos e jogados dentro das funções de membro [do CArchive.](../../mfc/reference/carchive-class.md) Você pode acessar esses objetos no escopo de uma expressão **CATCH.** O código de causa é independente do sistema operacional. Para obter mais informações sobre o processamento de exceções, consulte [MFC (Exception Handling, tratamento de exceção).](../../mfc/exception-handling-in-mfc.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`CArchiveException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="carchiveexceptioncarchiveexception"></a><a name="carchiveexception"></a>CArchiveException::CArchiveException

Constrói um `CArchiveException` objeto, armazenando o valor da *causa* no objeto.

```
CArchiveException(
    int cause = CArchiveException::none,
    LPCTSTR lpszArchiveName = NULL);
```

### <a name="parameters"></a>Parâmetros

*Causa*<br/>
Uma variável de tipo enumerada que indica a razão da exceção. Para obter uma lista dos enumeradores, consulte o membro de dados [m_cause.](#m_cause)

*lpszArchiveName*<br/>
Aponta para uma string contendo `CArchive` o nome do objeto causando a exceção.

### <a name="remarks"></a>Comentários

Você pode `CArchiveException` criar um objeto no heap e jogá-lo você mesmo ou deixar a função global [AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception) lidar com ele para você.

Não utilize este construtor diretamente; em vez disso, `AfxThrowArchiveException`chame a função global.

## <a name="carchiveexceptionm_cause"></a><a name="m_cause"></a>CArchiveException::m_cause

Especifica a causa da exceção.

```
int m_cause;
```

### <a name="remarks"></a>Comentários

Este membro de dados é uma variável pública de tipo **int**. Seus valores são `CArchiveException` definidos por um tipo enumerado. Os enumeradores e seus significados são os seguintes:

- `CArchiveException::none`Nenhum erro ocorreu.

- `CArchiveException::genericException`Erro não especificado.

- `CArchiveException::readOnly`Tentei escrever em um arquivo aberto para carregamento.

- `CArchiveException::endOfFile`Chegou ao fim do arquivo durante a leitura de um objeto.

- `CArchiveException::writeOnly`Tentei ler de um arquivo aberto para armazenar.

- `CArchiveException::badIndex`Formato de arquivo inválido.

- `CArchiveException::badClass`Tentou ler um objeto em um objeto do tipo errado.

- `CArchiveException::badSchema`Tentei ler um objeto com uma versão diferente da classe.

    > [!NOTE]
    >  Esses enumeradores de causa de `CArchiveException` são diferentes dos enumeradores de causa de `CFileException`.

    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em vez disso. Se **o genérico** for usado em um aplicativo e construído com /clr, haverá erros de sintaxe que não são fáceis de decifrar.

## <a name="carchiveexceptionm_strfilename"></a><a name="m_strfilename"></a>CArchiveException::m_strFileName

Especifica o nome do arquivo para esta condição de exceção.

```
CString m_strFileName;
```

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CArchive](../../mfc/reference/carchive-class.md)<br/>
[AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception)<br/>
[Processamento de exceção](../../mfc/reference/exception-processing.md)
