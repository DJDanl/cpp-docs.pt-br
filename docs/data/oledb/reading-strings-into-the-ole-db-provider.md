---
title: Lendo cadeias de caracteres no provedor de banco de dados OLE
ms.date: 10/13/2018
helpviewer_keywords:
- OLE DB providers, reading strings into
ms.assetid: 517f322c-f37e-4eed-bf5e-dd9a412c2f98
ms.openlocfilehash: d46b4e1a53e7e489763f40e7a5238e65b493f7c8
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59027422"
---
# <a name="reading-strings-into-the-ole-db-provider"></a>Lendo cadeias de caracteres no provedor de banco de dados OLE

O `CCustomRowset::Execute` função abre um arquivo e lê as cadeias de caracteres. O consumidor transmite o nome do arquivo para o provedor, chamando [ICommandText:: SetCommandText](/previous-versions/windows/desktop/ms709757(v=vs.85)). O provedor recebe o nome do arquivo e o armazena na variável de membro `m_strCommandText`. `Execute` lê o nome do arquivo de `m_strCommandText`. Se o nome do arquivo é inválido ou não estiver disponível, o arquivo `Execute` retornará um erro. Caso contrário, ele abre o arquivo e chama `fgets` para recuperar as cadeias de caracteres. Para cada conjunto de cadeias de caracteres-leituras, `Execute` cria uma instância de registro do usuário (modificado `CCustomWindowsFile` partir [armazenar cadeias de caracteres no provedor OLE DB](../../data/oledb/storing-strings-in-the-ole-db-provider.md)) e o coloca em uma matriz.

Se o arquivo não pode ser aberto, `Execute` deve retornar DB_E_NOTABLE. Se ele retornar E_FAIL em vez disso, o provedor não funcionará com muitos consumidores e não passar o OLE DB [testes de conformidade](../../data/oledb/testing-your-provider.md).

## <a name="example"></a>Exemplo

```cpp
/////////////////////////////////////////////////////////////////////////
// CustomRS.h
class CCustomRowset : public CRowsetImpl< CCustomRowset, CCustomWindowsFile, CCustomCommand>
{
public:
    HRESULT Execute(DBPARAMS * pParams, LONG* pcRowsAffected)
    {
        enum {
            sizeOfBuffer = 256,
            sizeOfFile = MAX_PATH
        };
        USES_CONVERSION;
        FILE* pFile = NULL;
        TCHAR szString[sizeOfBuffer];
        TCHAR szFile[sizeOfFile];
        size_t nLength;

        ObjectLock lock(this);

        // From a filename, passed in as a command text, scan the file
        // placing data in the data array.
        if (!m_strCommandText)
        {
            ATLTRACE("No filename specified");
            return E_FAIL;
        }

        // Open the file
        _tcscpy_s(szFile, sizeOfFile, m_strCommandText);
        if (szFile[0] == _T('\0') ||
            (fopen_s(&pFile, (char*)&szFile[0], "r") == 0))
        {
            ATLTRACE("Could not open file");
            return DB_E_NOTABLE;
        }

        // Scan and parse the file.
        // The file should contain two strings per record
        LONG cFiles = 0;
        while (fgets((char*)szString, sizeOfBuffer, pFile) != NULL)
        {
            nLength = strnlen((char*)szString, sizeOfBuffer);
            szString[nLength-1] = '\0';   // Strip off trailing CR/LF
            CCustomWindowsFile am;
            _tcscpy_s(am.szCommand, am.iSize, szString);
            _tcscpy_s(am.szCommand2, am.iSize, szString);

            if (fgets((char*)szString, sizeOfBuffer, pFile) != NULL)
            {
                nLength = strnlen((char*)szString, sizeOfBuffer);
                szString[nLength-1] = '\0'; // Strip off trailing CR/LF
                _tcscpy_s(am.szText, am.iSize, szString);
                _tcscpy_s(am.szText2, am.iSize, szString);
            }

            am.dwBookmark = ++cFiles;
            if (!m_rgRowData.Add(am))
            {
                ATLTRACE("Couldn't add data to array");
                fclose(pFile);
                return E_FAIL;
            }
        }

        if (pcRowsAffected != NULL)
            *pcRowsAffected = cFiles;
        return S_OK;
    }
};
```

Quando isso for feito, o provedor deve estar pronto para compilar e executar. Para testar o provedor, você precisa de um consumidor com a funcionalidade correspondente. [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md) mostra como criar tal um consumidor de teste. Execute o consumidor de teste com o provedor e verifique se que o consumidor de teste recupera as cadeias de caracteres apropriadas do provedor.

Quando você testou com êxito seu provedor, você talvez queira aprimorar sua funcionalidade ao implementar interfaces adicionais. Um exemplo é mostrado na [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).

## <a name="see-also"></a>Consulte também

[Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)<br/>
