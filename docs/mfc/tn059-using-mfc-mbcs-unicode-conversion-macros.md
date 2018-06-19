---
title: 'TN059: Usando Macros de conversão de Unicode em MBCS MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.mbcs
dev_langs:
- C++
helpviewer_keywords:
- MFCANS32.DLL
- Unicode [MFC], conversion macros
- Unicode [MFC], OLE interfaces
- conversion macros [MFC]
- converting Unicode
- MBCS [MFC], conversion macros
- macros [MFC], MBCS conversion macros
- TN059
ms.assetid: a2aab748-94d0-4e2f-8447-3bd07112a705
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 379c5b4fb9ed302ad1ea0167f2b32c30e48ab2bf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33384284"
---
# <a name="tn059-using-mfc-mbcsunicode-conversion-macros"></a>TN059: usando macros de conversão MBCS/Unicode MFC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve como usar as macros de conversão MBCS/Unicode, que são definidos no AFXPRIV. H. Essas macros são muito úteis se seu aplicativo de negócios diretamente com a API OLE ou por algum motivo, geralmente precisa converter entre Unicode e MBCS.  
  
## <a name="overview"></a>Visão geral  
 Em MFC 3. x, uma DLL especial foi usada (MFCANS32. DLL) para converter automaticamente entre Unicode e MBCS quando interfaces OLE foram chamados. Essa DLL foi uma camada transparente quase que aplicativos OLE a ser gravado como se as interfaces e APIs OLE foram MBCS, mesmo que eles sejam sempre Unicode permitidos (exceto no Macintosh). Enquanto essa camada foi conveniente e aplicativos para ser movido rapidamente de Win16 para Win32 permitidos (MFC, Microsoft Word, Microsoft Excel e VBA, são apenas alguns dos aplicativos da Microsoft usados por esta tecnologia), que tinha um desempenho significativo, às vezes, de ocorrências. Por esse motivo, MFC 4. x não usar essa DLL e em vez disso, se comunica diretamente com as interfaces OLE do Unicode. Para fazer isso, MFC precisa converter em Unicode em MBCS ao fazer uma chamada para uma interface OLE e geralmente precisa converter em MBCS de Unicode ao implementar uma interface OLE. Para lidar com isso facilmente e com eficiência, um número de macros foram criados para facilitar essa conversão.  
  
 Uma das maiores dificuldades de criação desses conjuntos de macros é alocação de memória. Porque as cadeias de caracteres não podem ser convertidas em vigor, a nova memória para armazenar os resultados convertidos deve ser alocada. Isso poderia ter sido feito com o código semelhante ao seguinte:  
  
```  
// we want to convert an MBCS string in lpszA  
int nLen = MultiByteToWideChar(CP_ACP,
    0,
    lpszA, -1,
    NULL,
    NULL);

LPWSTR lpszW = new WCHAR[nLen];  
MultiByteToWideChar(CP_ACP,
    0,   
    lpszA, -1,
    lpszW,
    nLen);

// use it to call OLE here  
pI->SomeFunctionThatNeedsUnicode(lpszW);

// free the string  
delete[] lpszW;  
```  
  
 Essa abordagem como um número de problemas. O principal problema é que se trata de um lote de código para escrever, testar e depurar. Algo que era uma chamada de função simples, é muito mais complexo. Além disso, há um tempo de execução significativo sobrecarga dessa forma. Memória deve ser alocada no heap e liberado sempre que uma conversão é feita. Por fim, o código acima precisaria apropriado `#ifdefs` adicionado para compilações de Unicode e Macintosh (que não requeiram essa conversão ocorra).  
  
 A solução que criamos é criar algumas macros que 1) máscara a diferença entre as várias plataformas e 2) use um esquema de alocação de memória eficiente e 3) são fácil inserir existente código-fonte. Aqui está um exemplo de uma das definições:  
  
```  
#define A2W(lpa) (\  
 ((LPCSTR)lpa == NULL) NULL : (\  
    _convert = (strnlen(lpa)+1),\  
    AfxA2WHelper((LPWSTR) alloca(_convert*2),   
    lpa,
    _convert)\)\)  
```  
  
 Usando essa macro em vez do código acima e coisas são muito mais simples:  
  
```  
// use it to call OLE here  
USES_CONVERSION;  
pI->SomeFunctionThatNeedsUnicode(T2OLE(lpszA));
```  
  
 Há extras chamadas em que a conversão é necessária, mas usar as macros é simples e eficiente.  
  
 A implementação de cada macro usa a função alloca () para alocar a memória da pilha, em vez de heap. Alocação de memória da pilha é muito mais rápido que a alocação de memória no heap e a memória é liberada automaticamente quando a função for fechada. Além disso, as macros Evite chamar **MultiByteToWideChar** (ou **WideCharToMultiByte**) mais de uma vez. Isso é feito ao alocar um pouco mais memória do que é necessário. Sabemos que um MBC converterá no máximo uma **WCHAR** e para cada **WCHAR** teremos um máximo de dois bytes MBC. Alocando um pouco mais do que o necessário, mas sempre é suficiente para lidar com a conversão a segunda chamada segunda chamada para a função de conversão é evitada. A chamada para a função auxiliar **AfxA2Whelper** reduz o número de envios por push de argumento deve ser feito para realizar a conversão (Isso resulta em código menor, que se chamado **MultiByteToWideChar**diretamente).  
  
 Em ordem para macros tenha espaço para armazenar o comprimento temporário, é necessário declarar uma variável local chamada converter em que faz isso em cada função que usa as macros de conversão. Isso é feito chamando a **USES_CONVERSION** macro, como mostra o exemplo acima.  
  
 Há macros de conversão genérico e macros específicas de OLE. Esses dois conjuntos diferentes de macro são discutidos abaixo. Todas as macros residem no AFXPRIV. H.  
  
## <a name="generic-conversion-macros"></a>Macros de conversão genérico  
 As macros de conversão genérico formam o mecanismo subjacente. O exemplo de macro e a implementação mostrado na seção anterior, A2W, é uma macro tal "genérica". Ele não está relacionado a OLE especificamente. O conjunto de macros genéricos é listado abaixo:  
  
```  
A2CW      (LPCSTR) -> (LPCWSTR)  
A2W      (LPCSTR) -> (LPWSTR)  
W2CA      (LPCWSTR) -> (LPCSTR)  
W2A      (LPCWSTR) -> (LPSTR)  
```  
  
 Além de fazer conversões de texto, também há macros e funções auxiliares para converter `TEXTMETRIC`, `DEVMODE`, `BSTR`e OLE alocada cadeias de caracteres. Essas macros estão além do escopo desta discussão - consulte AFXPRIV. H para obter mais informações sobre essas macros.  
  
## <a name="ole-conversion-macros"></a>Macros de conversão de OLE  
 As macros de conversão de OLE são projetadas especificamente para manipular funções que esperam **OLESTR** caracteres. Se você examinar os cabeçalhos OLE, você verá muitas referências a **LPCOLESTR** e **OLECHAR**. Esses tipos são usados para se referir ao tipo de caracteres usado nas interfaces de OLE de uma maneira que não é específico para a plataforma. **OLECHAR** mapeia para `char` nas plataformas Win16 e Macintosh e **WCHAR** no Win32.  
  
 Para manter o número de **#ifdef** diretivas em MFC código mínimo temos uma macro semelhante para cada conversão que onde as cadeias de caracteres OLE estão envolvidas. As seguintes macros são mais usadas:  
  
```  
T2COLE   (LPCTSTR) -> (LPCOLESTR)  
T2OLE   (LPCTSTR) -> (LPOLESTR)  
OLE2CT   (LPCOLESTR) -> (LPCTSTR)  
OLE2T   (LPCOLESTR) -> (LPCSTR)  
```  
  
 Novamente, existem macros semelhantes para fazer `TEXTMETRIC`, `DEVMODE`, `BSTR`e OLE alocada cadeias de caracteres. Consulte AFXPRIV. H para obter mais informações.  
  
## <a name="other-considerations"></a>Outras considerações  
 Não use as macros em um loop estreito. Por exemplo, você não deseja gravar o seguinte tipo de código:  
  
```  
void BadIterateCode(LPCTSTR lpsz)  
{  
    USES_CONVERSION; 
    for (int ii = 0; ii <10000; ii++)  
    pI->SomeMethod(ii, T2COLE(lpsz));

}  
```  
  
 O código acima pode resultar na alocação de megabytes de memória na pilha dependendo do que o conteúdo da cadeia de caracteres `lpsz` é! Ele também usa o tempo necessário para converter a cadeia de caracteres para cada iteração do loop. Em vez disso, mova tais conversões constantes fora do loop:  
  
```  
void MuchBetterIterateCode(LPCTSTR lpsz)  
{  
    USES_CONVERSION; 
    LPCOLESTR lpszT = T2COLE(lpsz);

    for (int ii = 0; ii <10000; ii++)  
    pI->SomeMethod(ii, lpszT);

}  
```  
  
 Se a cadeia de caracteres não é constante, em seguida, encapsulam a chamada de método em uma função. Isso permitirá que o buffer de conversão de cada vez. Por exemplo:  
  
```  
void CallSomeMethod(int ii, LPCTSTR lpsz)  
{  
    USES_CONVERSION; 
    pI->SomeMethod(ii, T2COLE(lpsz));

}  
 
void MuchBetterIterateCode2(LPCTSTR* lpszArray)  
{  
    for (int ii = 0; ii <10000; ii++)  
    CallSomeMethod(ii, lpszArray[ii]);

}  
```  
  
 Nunca retornam o resultado de uma das macros, a menos que o valor de retorno indica a fazer uma cópia dos dados antes de retornar. Por exemplo, esse código é inválido:  
  
```  
LPTSTR BadConvert(ISomeInterface* pI)  
{  
    USES_CONVERSION; 
    LPOLESTR lpsz = NULL;  
    pI->GetFileName(&lpsz);

 LPTSTR lpszT = OLE2T(lpsz);

    CoMemFree(lpsz);

 return lpszT; // bad! returning alloca memory  
}  
```  
  
 O código acima pode ser corrigido, alterando o valor de retorno para algo que copia o valor:  
  
```  
CString BetterConvert(ISomeInterface* pI)  
{  
    USES_CONVERSION; 
    LPOLESTR lpsz = NULL;  
    pI->GetFileName(&lpsz);

 LPTSTR lpszT = OLE2T(lpsz);

    CoMemFree(lpsz);

 return lpszT; // CString makes copy  
}  
```  
  
 As macros são fáceis de usar e fácil inserir em seu código, mas como você pode dizer sobre as condições acima, você precisa ter cuidado ao usá-los.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

