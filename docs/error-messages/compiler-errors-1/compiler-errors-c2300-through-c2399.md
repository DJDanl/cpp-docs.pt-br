---
title: Erros de compilador C2300 a C2399 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2303
- C2304
- C2305
- C2306
- C2314
- C2321
- C2323
- C2328
- C2329
- C2330
- C2331
- C2335
- C2336
- C2339
- C2340
- C2342
- C2343
- C2347
- C2354
- C2358
- C2359
- C2363
- C2366
- C2367
- C2398
- C2399
helpviewer_keywords:
- C2303
- C2304
- C2305
- C2306
- C2314
- C2321
- C2323
- C2328
- C2329
- C2330
- C2331
- C2335
- C2336
- C2339
- C2340
- C2342
- C2343
- C2347
- C2354
- C2358
- C2359
- C2363
- C2366
- C2367
- C2398
- C2399
dev_langs: C++
ms.assetid: 07ca45b5-b2f0-4049-837b-40a7a3caed88
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f8e1dcf350c974f5be96b971d3d70e69b95ebc9e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-errors-c2300-through-c2399"></a>Erros do Compilador C2300 a C2399
Os artigos nesta parte da documentação contêm informações sobre uma subseção de erros do compilador do Visual C++. Você pode acessar as informações aqui ou no **saída** janela no Visual Studio, você pode selecionar um número de erro e, em seguida, escolha a tecla F1.  
  
> [!NOTE]
>  Nem todo [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] erro está documentado no MSDN. Em muitos casos, a mensagem de diagnóstica fornece todas as informações que estão disponíveis. Se você achar que precisa de uma mensagem de erro explicação adicional, você poderá nos informar. Use o formulário de comentários nesta página, ou vá para a barra de menus do Visual Studio e escolha **ajuda**, **relatar um erro**, ou você pode enviar um relatório de sugestão ou um bug no [Microsoft Connect](http://connect.microsoft.com/VisualStudio).  
  
 Você pode obter assistência adicional para erros e avisos nos fóruns públicos do MSDN. O [linguagem Visual C++](http://go.microsoft.com/fwlink/?LinkId=158195) fórum é para perguntas e discussões sobre o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] sintaxe de linguagem e compilador. O [geral do Visual C++](http://go.microsoft.com/fwlink/?LinkId=158194) fórum é para perguntas sobre [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] que não são abordados em outros fóruns. Você também pode encontrar ajuda sobre erros e avisos sobre [estouro de pilha](http://stackoverflow.com/).  
  
|Erro|Mensagem|  
|-----------|-------------|  
|[Erro do compilador C2300](compiler-error-c2300.md)|'*classe*': classe não tem um destruidor chamado ' ~*classe*'|  
|[Erro do compilador C2301](compiler-error-c2301.md)|esquerda de ' -> ~*identificador*' deve apontar para classe/struct/união|  
|[Erro do compilador C2302](compiler-error-c2302.md)|esquerda de '. ~*identificador*' deve ter o tipo de classe/struct/união|  
|C2303 de erro do compilador|Tratamento estruturado de exceções não pode ser usado em uma corrotina|  
|C2304 de erro do compilador|'*palavra-chave*' não pode ser usado dentro de um bloco catch|  
|C2305 de erro do compilador|'*arquivo*' não contém informações de depuração para este módulo|  
|C2306 de erro do compilador|'*arquivo*' não contém as informações de depuração mais recentes para este módulo|  
|[Erro do compilador C2307](compiler-error-c2307.md)|pragma *diretiva* deve ser movido para fora a função se compilação incremental estiver habilitada|  
|[Erro do compilador C2308](compiler-error-c2308.md)|concatenando cadeias de caracteres incompatíveis|  
|[Erro do compilador C2309](compiler-error-c2309.md)|manipulador catch esperava uma declaração de exceção entre parênteses|  
|[Erro do compilador C2310](compiler-error-c2310.md)|manipuladores catch devem especificar um tipo|  
|[Erro do compilador C2311](compiler-error-c2311.md)|'*tipo*': é capturado por '...' na linha *número*|  
|[Erro do compilador C2312](compiler-error-c2312.md)|'*type1*': é capturado por '*type2*' na linha *número*|  
|[Erro do compilador C2313](compiler-error-c2313.md)|'*type1*': é capturado por referência ('*type2*') na linha *número*|  
|C2314 de erro do compilador|palavra-chave '*keyword1*' foi preterida: usar '*keyword2*' em vez disso|  
|[Erro do compilador C2315](compiler-error-c2315.md)|'*type1*': referência é capturada por '*type2*' na linha *número*|  
|[Erro do compilador C2316](compiler-error-c2316.md)|'*tipo*': não pode ser capturado porque o destruidor e/ou o construtor de cópia é inacessíveis ou foram excluídos|  
|[Erro do compilador C2317](compiler-error-c2317.md)|'try' começando na linha de bloco '*número*' não possui manipuladores catch|  
|[Erro do compilador C2318](compiler-error-c2318.md)|nenhum bloco try associado a este manipulador catch|  
|[Erro do compilador C2319](compiler-error-c2319.md)|' try/catch' deve ser seguido por uma instrução composta. Faltando ' {'|  
|[Erro do compilador C2320](compiler-error-c2320.md)|esperado ':' a seguir especificador de acesso '*especificador*'|  
|C2321 de erro do compilador|'*identificador*' é uma palavra-chave e não pode ser usado neste contexto|  
|[Erro do compilador C2322](compiler-error-c2322.md)|'*identificador*': endereço de dllimport '*identificador*' não é estático|  
|C2323 de erro do compilador|'*identificador*': operador não membro novo ou funções de exclusão não podem ser declaradas estática ou em um namespace diferente do namespace global|  
|[Erro do compilador C2324](compiler-error-c2324.md)|'*identificador*': inesperado à direita de ':: ~'|  
|[Erro do compilador C2325](compiler-error-c2325.md)|'*type1*': tipo inesperado à direita de ' -> ~': esperado '*type2*'|  
|[Erro do compilador C2326](compiler-error-c2326.md)|'*declarador*': função não é possível acessar '*identificador*'|  
|[Erro do compilador C2327](compiler-error-c2327.md)|'*identificador*': não é um nome de tipo, static ou enumerador|  
|C2328 de erro do compilador|'*palavra-chave*': palavra-chave ainda não é suportada|  
|C2329 de erro do compilador|'*identificador*': ptr64 não disponível para ponteiros para funções|  
|C2330 de erro do compilador|'implementation_key ()' só é válido em uma região limitada por #pragma start_map_region/stop_map_region|  
|C2331 de erro do compilador|acesso a '*identificador*'agora definido como'*accessibility1*', anteriormente foi definido para ser'*accessibility2*'|  
|[Erro do compilador C2332](compiler-error-c2332.md)|'*typedef*': faltando nome de marca|  
|[Erro do compilador C2333](compiler-error-c2333.md)|'*função*': erro na declaração de função; ignorando corpo de função|  
|[Erro do compilador C2334](compiler-error-c2334.md)|tokens inesperados anterior '*token*'; ignorando corpo aparente de função|  
|C2335 de erro do compilador|'*identificador*': um tipo não pode ser introduzido em uma lista de parâmetros de função|  
|C2336 de erro do compilador|'*tipo*': tipo inválido|  
|[Erro do compilador C2337](compiler-error-c2337.md)|'*atributo*': atributo não encontrado|  
|[Erro do compilador C2338](compiler-error-c2338.md)|*(mensagem de erro do provedor externo)*|  
|C2339 de erro do compilador|'*identificador*': tipo inválido em IDL inserida|  
|C2340 de erro do compilador|'*identificador*': 'static' só pode ser usado em uma definição de classe|  
|[Erro do compilador C2341](compiler-error-c2341.md)|'*seção*': segmento deve ser definido usando #pragma data_seg, code_seg ou section antes de usar|  
|C2342 de erro do compilador|Erro de sintaxe: qualificadores de tipo conflitante|  
|C2343 de erro do compilador|'*seção*': atributos de seção conflitantes|  
|[Erro do compilador C2344](compiler-error-c2344.md)|Alinhar (*número*): alinhamento deve ser uma potência de dois|  
|[Erro do compilador C2345](compiler-error-c2345.md)|Alinhar (*número*): valor de alinhamento inválido|  
|[Erro do compilador C2346](compiler-error-c2346.md)|'*função*' não pode ser compilado como nativo: '*explicação*'|  
|C2347 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2348](compiler-error-c2348.md)|'*tipo*': não é uma agregação C-style, não pode ser exportada em IDL inserida|  
|[Erro do compilador C2349](compiler-error-c2349.md)|'*função*' não pode ser compilado como gerenciado: '*explicação*'; use #pragma não gerenciado|  
|[Erro do compilador C2350](compiler-error-c2350.md)|'*identificador*' não é um membro estático|  
|[Erro do compilador C2351](compiler-error-c2351.md)|sintaxe de inicialização de construtor de C++ obsoleta|  
|[Erro do compilador C2352](compiler-error-c2352.md)|'*identificador*': chamada inválida a função de membro não estático|  
|[Erro do compilador C2353](compiler-error-c2353.md)|não é permitida a especificação de exceção|  
|C2354 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2355](compiler-error-c2355.md)|'this': só pode ser referenciada dentro de funções de membro não estático ou inicializadores de membros de dados não estático|  
|[Erro do compilador C2356](compiler-error-c2356.md)|segmento de inicialização não deve mudar durante unidade de tradução|  
|[Erro do compilador C2357](compiler-error-c2357.md)|'*identificador*': deve ser uma função do tipo '*tipo*'|  
|C2358 de erro do compilador|'*identificador*': uma propriedade estática não pode ser definida fora de uma definição de classe|  
|C2359 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2360](compiler-error-c2360.md)|inicialização de '*identificador*' é ignorada por rótulo 'case'|  
|[Erro do compilador C2361](compiler-error-c2361.md)|inicialização de '*identificador*' é ignorada por rótulo 'default'|  
|[Erro do compilador C2362](compiler-error-c2362.md)|inicialização de '*identificador*' é ignorada por ' goto *rótulo*'|  
|C2363 de erro do compilador|função de limite numérico intrínseco do compilador requer um argumento de cadeia de caracteres literal|  
|[Erro do compilador C2364](compiler-error-c2364.md)|'*tipo*': tipo inválido para atributo personalizado|  
|[Erro do compilador C2365](compiler-error-c2365.md)|'*membro1*': redefinição; definição anterior era '*membro2*'|  
|C2366 de erro do compilador|'*identificador*': redefinição; especificadores implementation_key diferentes|  
|C2367 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2368](compiler-error-c2368.md)|'*identificador*': redefinição; especificadores de alocação diferentes|  
|[Erro do compilador C2369](compiler-error-c2369.md)|'*identificador*': redefinição; subscritos diferentes|  
|[Erro do compilador C2370](compiler-error-c2370.md)|'*identificador*': redefinição; classe de armazenamento diferente|  
|[Erro do compilador C2371](compiler-error-c2371.md)|'*identificador*': redefinição; tipos básicos diferentes|  
|[Erro do compilador C2372](compiler-error-c2372.md)|'*identificador*': redefinição; tipos diferentes de indireção|  
|[Erro do compilador C2373](compiler-error-c2373.md)|'*identificador*': redefinição; modificadores de tipo diferentes|  
|[Erro do compilador C2374](compiler-error-c2374.md)|'*identificador*': redefinição; inicialização vários|  
|[Erro do compilador C2375](compiler-error-c2375.md)|'*identificador*': redefinição; vinculação diferente|  
|[Erro do compilador C2376](compiler-error-c2376.md)|'*identificador*': redefinição; alocação based diferente|  
|[Erro do compilador C2377](compiler-error-c2377.md)|'*identificador*': redefinição; typedef não pode ser sobrecarregado com nenhum outro símbolo|  
|[Erro do compilador C2378](compiler-error-c2378.md)|'*identificador*': redefinição; símbolo não pode ser sobrecarregado com um typedef|  
|[Erro do compilador C2379](compiler-error-c2379.md)|parâmetro formal *número* possui tipo diferente quando promovido|  
|[Erro do compilador C2380](compiler-error-c2380.md)|tipo (s) anterior '*identificador*' (construtor com tipo de retorno ou redefinição inválida do nome de classe atual?)|  
|[Erro do compilador C2381](compiler-error-c2381.md)|'*identificador*': redefinição; '__declspec(noreturn)' ou '[[noreturn]]' é diferente|  
|[Erro do compilador C2382](compiler-error-c2382.md)|'*identificador*': redefinição; especificações de exceção diferente|  
|[Erro do compilador C2383](compiler-error-c2383.md)|'*identificador*': argumentos padrão não são permitidos neste símbolo|  
|[Erro do compilador C2384](compiler-error-c2384.md)|'*membro*': não é possível aplicar thread_local ou __declspec(thread) a um membro de uma classe gerenciada/WinRT|  
|[Erro do compilador C2385](compiler-error-c2385.md)|acesso ambíguo de '*membro*'|  
|[Erro do compilador C2386](compiler-error-c2386.md)|'*identificador*': um símbolo com este nome já existe no escopo atual|  
|[Erro do compilador C2387](compiler-error-c2387.md)|'*identificador*': classe base ambígua|  
|[Erro do compilador C2388](compiler-error-c2388.md)|'*identificador*': um símbolo não pode ser declarado com __declspec(appdomain) e __declspec(process)|  
|[Erro do compilador C2389](compiler-error-c2389.md)|'*operador*': operando inválido 'nullptr'|  
|[Erro do compilador C2390](compiler-error-c2390.md)|'*identificador*': classe de armazenamento incorreta*especificador*'|  
|[Erro do compilador C2391](compiler-error-c2391.md)|'*identificador*': 'friend' não pode ser usado durante a definição de tipo|  
|[Erro do compilador C2392](compiler-error-c2392.md)|'*membro1*': retornos covariantes tipos não têm suporte em tipos gerenciados/WinRT, caso contrário '*membro2*' deve ser substituído|  
|[Erro do compilador C2393](compiler-error-c2393.md)|'*símbolo*': símbolo per-appdomain não pode ser alocado no segmento '*segmento*'|  
|[Erro do compilador C2394](compiler-error-c2394.md)|'*tipo*:: operador *operador*': CLR/WinRT operador não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' t ^', ' t ^ %', ' t ^ &', onde T = '*tipo*'|  
|[Erro do compilador C2395](compiler-error-c2395.md)|'*tipo*:: operador *operador*': CLR/WinRT operador não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' t ', ' t %', ' t &', ' t ^', ' t ^ %', ' t ^ &', onde T = '*tipo*'|  
|[Erro do compilador C2396](compiler-error-c2396.md)|'*type1*:: operador *type2*': função de conversão definida pelo usuário CLR/WinRT não é válida. Deve converter de ou converter em: ' t ^', ' t ^ %', ' t ^ &', onde T = '*type1*'|  
|[Erro do compilador C2397](compiler-error-c2397.md)|conversão de '*type1*'para'*type2*' requer uma conversão de restrição|  
|C2398 de erro do compilador|Elemento '*número*': conversão de '*type1*'para'*type2*' requer uma conversão de restrição|  
|C2399 de erro do compilador|Obsoleto.|  
