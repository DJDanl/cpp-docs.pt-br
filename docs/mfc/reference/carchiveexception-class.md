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
ms.openlocfilehash: 731735bccf9225e67d82b1fe90336c92a630b368
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420648"
---
# <a name="carchiveexception-class"></a>Classe CArchiveException

Representa uma condição de exceção de serialização

## <a name="syntax"></a>Sintaxe

```
class CArchiveException : public CException
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArchiveException::CArchiveException](#carchiveexception)|Constrói um objeto `CArchiveException`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CArchiveException:: m_cause](#m_cause)|Indica a causa da exceção.|
|[CArchiveException:: m_strFileName](#m_strfilename)|Especifica o nome do arquivo para esta condição de exceção.|

## <a name="remarks"></a>Comentários

A classe `CArchiveException` inclui um membro de dados público que indica a causa da exceção.

`CArchiveException` objetos são construídos e lançados dentro de funções de membro [CArchive](../../mfc/reference/carchive-class.md) . Você pode acessar esses objetos dentro do escopo de uma expressão **Catch** . O código de causa é independente do sistema operacional. Para obter mais informações sobre o processamento de exceções, consulte [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CArchiveException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="carchiveexception"></a>CArchiveException::CArchiveException

Constrói um objeto `CArchiveException`, armazenando o valor de *causa* no objeto.

```
CArchiveException(
    int cause = CArchiveException::none,
    LPCTSTR lpszArchiveName = NULL);
```

### <a name="parameters"></a>parâmetros

*causa*<br/>
Uma variável de tipo enumerada que indica o motivo da exceção. Para obter uma lista dos enumeradores, consulte o membro de dados [m_cause](#m_cause) .

*lpszArchiveName*<br/>
Aponta para uma cadeia de caracteres que contém o nome do objeto `CArchive` que está causando a exceção.

### <a name="remarks"></a>Comentários

Você pode criar um objeto `CArchiveException` no heap e jogá-lo por conta própria ou deixar que a função global [AfxThrowArchiveException](../../mfc/reference/exception-processing.md#afxthrowarchiveexception) manipule-o para você.

Não use esse construtor diretamente; em vez disso, chame a função global `AfxThrowArchiveException`.

##  <a name="m_cause"></a>CArchiveException:: m_cause

Especifica a causa da exceção.

```
int m_cause;
```

### <a name="remarks"></a>Comentários

Esse membro de dados é uma variável pública do tipo **int**. Seus valores são definidos por um `CArchiveException` tipo enumerado. Os enumeradores e seus significados são os seguintes:

- Não `CArchiveException::none` erro.

- `CArchiveException::genericException` erro não especificado.

- `CArchiveException::readOnly` tentou gravar em um arquivo morto aberto para carregamento.

- `CArchiveException::endOfFile` chegou ao fim do arquivo durante a leitura de um objeto.

- `CArchiveException::writeOnly` tentou ler de um arquivo morto aberto para armazenamento.

- `CArchiveException::badIndex` formato de arquivo inválido.

- `CArchiveException::badClass` tentou ler um objeto em um objeto do tipo errado.

- `CArchiveException::badSchema` tentou ler um objeto com uma versão diferente da classe.

    > [!NOTE]
    >  Esses enumeradores de causa de `CArchiveException` são diferentes dos enumeradores de causa de `CFileException`.

    > [!NOTE]
    > O `CArchiveException::generic` foi preterido. Use `genericException` em vez disso. Se **genérico** for usado em um aplicativo e criado com/CLR, haverá erros de sintaxe que não são fáceis de decifrar.

##  <a name="m_strfilename"></a>CArchiveException:: m_strFileName

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
