---
title: "TN059: usando macros de convers&#227;o MBCS/Unicode MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.mbcs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macros de conversão [C++]"
  - "convertendo Unicode"
  - "macros [C++], macros de conversão MBCS"
  - "MBCS [C++], macros de conversão"
  - "MFCANS32.DLL"
  - "TN059"
  - "Unicode [C++], macros de conversão"
  - "Unicode [C++], Interfaces OLE"
ms.assetid: a2aab748-94d0-4e2f-8447-3bd07112a705
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN059: usando macros de convers&#227;o MBCS/Unicode MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve como usar macros para a conversão de MBCS\/Unicode, que são definidos em AFXPRIV.H.  Macros esses são os mais úteis se seu aplicativo trata diretamente apis OLE ou por alguma razão, geralmente necessidades de conversão entre Unicode e MBCS.  
  
## Visão Geral  
 Em MFC 3.x, uma DLL especial foi usado MFCANS32.DLL \(\) para converter automaticamente entre Unicode e MBCS quando as interfaces OLE eram chamadas.  Este DLL era uma camada transparente quase que permite que os aplicativos OLE sejam gravados como se as APIs e as interfaces OLE eram MBCS, mesmo que sejam sempre Unicode \(exceto em Macintosh\).  Quando essa camada foi aplicativos convenientes e pode ser movido rapidamente de Win16 ao Win32 \(MFC o, o Microsoft Word, Microsoft Excel, e VBA, são apenas alguns dos aplicativos Microsoft que usava essa tecnologia\), tinha uma ocorrência às vezes de desempenho significativa.  Por esse motivo, o MFC 4.x não usa este DLL e não fala em vez de diretamente às interfaces OLE Unicode.  Para fazer isso, o MFC precisa da conversão para Unicode a MBCS ao fazer uma chamada a uma interface OLE, e geralmente às necessidades conversão em MBCS Unicode ao implementar uma interface OLE.  Para tratar eficiente e facilmente isso, um número de macros foram projetados para facilitar essa conversão.  
  
 Um dos obstáculos os maiores de criar esse conjunto de macros é alocação de memória.  Como as cadeias de caracteres não podem ser convertido no lugar, a nova memória para armazenar os resultados da conversão deve ser atribuída.  Isso pode ter sido feita com o código semelhante ao seguinte:  
  
```  
// we want to convert an MBCS string in lpszA  
int nLen = MultiByteToWideChar(CP_ACP, 0,lpszA, -1, NULL, NULL);  
LPWSTR lpszW = new WCHAR[nLen];  
MultiByteToWideChar(CP_ACP, 0,   
   lpszA, -1, lpszW, nLen);  
// use it to call OLE here  
pI->SomeFunctionThatNeedsUnicode(lpszW);  
// free the string  
delete[] lpszW;  
```  
  
 Essa abordagem como um número de problemas.  O problema é maior que é muito código para escrever, teste, e depuração.  Algo que era uma chamada de função simples, agora é muito mais complexo.  Além disso, há uma sobrecarga significativa de tempo de execução dessa forma.  A memória tem que ser atribuída no heap e ser liberada cada vez que uma conversão é feita.  Finalmente, o código anterior precisará ter adicionado `#ifdefs` apropriado para as construções Unicode e Macintosh \(que não exigem essa conversão ocorre\).  
  
 A solução que nós viemos superior com macros que é criar alguns 1\) mascarar a diferença entre as várias plataformas, e 2\) use um esquema de alocação de memória eficientes, e 3\) é fácil de ser inserida no código\-fonte existente.  Eis um exemplo de uma das definições:  
  
```  
#define A2W(lpa) (\  
    ((LPCSTR)lpa == NULL) ? NULL : (\  
          _convert = (strnlen(lpa)+1),\  
        AfxA2WHelper((LPWSTR) alloca(_convert*2),   
      lpa, _convert)\  
    )\  
)  
```  
  
 Usando esta macro em vez de código acima e itens é muito mais simples:  
  
```  
// use it to call OLE here  
USES_CONVERSION;  
pI->SomeFunctionThatNeedsUnicode(T2OLE(lpszA));  
```  
  
 Há as chamadas adicionais em que a conversão é necessária, mas usar macros é simples e eficiente.  
  
 A implementação de cada macro usa a função de \_alloca\(\) para alocar memória da pilha em vez do heap.  Alocar memória da pilha é muito mais rápida do que atribuindo a memória no heap, e a memória é liberada automaticamente quando a função é saída.  Além disso, as macros impedem **MultiByteToWideChar** chame \(ou\) **WideCharToMultiByte**mais de uma vez.  Isso é feito atribuindo um pouco mais memória que é necessário.  Aprendemos que um MBC se converterá no máximo em um **WCHAR** e que para cada **WCHAR** nós teremos um máximo de dois bytes do MBC.  Atribuindo um pouco mais do que o necessário, mas sempre suficiente para controlar a conversão a chamada de segundo segunda chamada à função de conversão é evitada.  A chamada para a função **AfxA2Whelper** auxiliar reduz o número de envios do argumento que devem ser feitas a fim de executar a conversão \(isso resulta em código, menor do que se ele **MultiByteToWideChar** chamado diretamente\).  
  
 Para que as macros têm espaço armazenando um comprimento temporário, é necessário declarar uma variável local chamada \_convert o que fazer isso em cada função que usa macros de conversão.  Isso é feito chamando a macro de **USES\_CONVERSION** como consultado no exemplo acima.  
  
 Há dois macros genéricas de conversão e um macros específicos do.  Esses dois conjuntos macro diferentes são discutidos em.  Todos os macros residem em. AFXPRIV.H.  
  
## Macros genéricas de conversão  
 Macros genéricas de conversão formam o mecanismo subjacente.  O exemplo e a implementação macro mostrados na seção anterior, A2W, é um como uma macro “genérico.  Não está relacionada ao OLE especificamente.  O conjunto de macros genéricas é listado abaixo:  
  
```  
A2CW      (LPCSTR) -> (LPCWSTR)  
A2W      (LPCSTR) -> (LPWSTR)  
W2CA      (LPCWSTR) -> (LPCSTR)  
W2A      (LPCWSTR) -> (LPSTR)  
```  
  
 Além de executar conversões de texto, também há macros e o auxiliar funções convertendo `TEXTMETRIC`, `DEVMODE`, `BSTR`, e cadeias de caracteres atribuídas OLE.  Esses são macros além do escopo desta discussão – consulte AFXPRIV.H para obter mais informações sobre esses macros.  
  
## Macros de conversão OLE  
 Macros OLE de conversão são criados especificamente para controlar as funções que esperam caracteres de **OLESTR** .  Se você examina os cabeçalhos OLE, você verá muitas referências a **LPCOLESTR** e a **OLECHAR**.  Esses tipos são usados para fazer referência ao tipo de caracteres usados em interfaces OLE em um modo que não é específica à plataforma.  Mapas de**OLECHAR** a `char` em plataformas de Win16 e Macintosh e a **WCHAR** no Win32.  
  
 Para manter o número de políticas de **\#ifdef** no código de MFC a um mínimo temos uma macro semelhante para cada conversão onde OLE cadeias de caracteres é envolvida.  Os seguintes macros são usados com mais frequência:  
  
```  
T2COLE   (LPCTSTR) -> (LPCOLESTR)  
T2OLE   (LPCTSTR) -> (LPOLESTR)  
OLE2CT   (LPCOLESTR) -> (LPCTSTR)  
OLE2T   (LPCOLESTR) -> (LPCSTR)  
```  
  
 Além disso, há macros semelhantes para fazer `TEXTMETRIC`, `DEVMODE`, `BSTR`, e cadeias de caracteres atribuídas OLE.  Consulte AFXPRIV.H para obter mais informações.  
  
## Outras considerações  
 Não use macros em um loop estreito.  Por exemplo, você não quiser escrever o seguinte tipo de código:  
  
```  
void BadIterateCode(LPCTSTR lpsz)  
{  
   USES_CONVERSION;  
   for (int ii = 0; ii < 10000; ii++)  
      pI->SomeMethod(ii, T2COLE(lpsz));  
}  
```  
  
 O código anterior pode resultar em megabytes atribuir de memória na pilha dependendo do que o conteúdo da cadeia de caracteres `lpsz` são\!  Também leva tempo converter a cadeia de caracteres para cada iteração do loop.  Em vez disso, mova tais conversões constantes fora do loop:  
  
```  
void MuchBetterIterateCode(LPCTSTR lpsz)  
{  
   USES_CONVERSION;  
   LPCOLESTR lpszT = T2COLE(lpsz);  
   for (int ii = 0; ii < 10000; ii++)  
      pI->SomeMethod(ii, lpszT);  
}  
```  
  
 Se a cadeia de caracteres não é constante, então encapsular a chamada do método em uma função.  Isso permitirá que o buffer de conversão é liberado cada vez.  Por exemplo:  
  
```  
void CallSomeMethod(int ii, LPCTSTR lpsz)  
{  
   USES_CONVERSION;  
   pI->SomeMethod(ii, T2COLE(lpsz));  
}  
  
void MuchBetterIterateCode2(LPCTSTR* lpszArray)  
{  
   for (int ii = 0; ii < 10000; ii++)  
      CallSomeMethod(ii, lpszArray[ii]);  
}  
```  
  
 Nunca retornar o resultado de um de macros, a menos que o valor de retorno implique a fatura de uma cópia dos dados antes de retorno.  Por exemplo, esse código é ruim:  
  
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
  
 O código anterior poderia ser solucionado alterando o valor de retorno a algo que copia o valor:  
  
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
  
 Macros são fáceis de usar e fáceis de inseri\-lo em seu código, mas como você pode saber das advertências acima, você precisa ter cuidado para usá\-las.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)