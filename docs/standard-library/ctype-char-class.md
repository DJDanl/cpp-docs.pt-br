---
title: "&lt; char &gt; classe CType | Microsoft Docs"
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
  - "ctype<char>"
  - "locale/std::ctype<char>"
  - "std::ctype<char>"
  - "std.ctype<char>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe CType < char >"
ms.assetid: ee30acb4-a743-405e-b3d4-13602092da84
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt; char &gt; classe CType
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe é uma especialização explícita da classe de modelo **ctype \< CharType**> para o tipo `char`, que descreve um objeto que pode servir como uma faceta de localidade para caracterizar várias propriedades de um caractere do tipo `char`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <>  
class ctype<char>  
: public ctype_base  
{  
public:  
    typedef char _Elem;  
    typedef _Elem char_type;  
    bool is(
    mask _Maskval,  
    _Elem _Ch) const;

 
    const _Elem* is(
    const _Elem* first,  
    const _Elem* last,  
    mask* dest) const;

 
    const _Elem* scan_is(
    mask _Maskval,  
    const _Elem* first,  
    const _Elem* last) const;

 
    const _Elem* scan_not(
    mask _Maskval,  
    const _Elem* first,  
    const _Elem* last) const;

 
    _Elem tolower(
    _Elem _Ch) const;

 
    const _Elem* tolower(
    _Elem* first,  
    const _Elem* last) const;

 
    _Elem toupper(
    _Elem _Ch) const;

 
    const _Elem* toupper(
    _Elem* first,  
    const _Elem* last) const;

 
    _Elem widen(
    char _Byte) const;

 
    const _Elem* widen(
    const char* first,  
    const char* last,  
    _Elem* dest) const;

 
    const _Elem* _Widen_s(
    const char* first,  
    const char* last,  
    _Elem* dest,  
    size_t dest_size) const;

 
    _Elem narrow(
    _Elem _Ch,  
    char _Dflt = '\0') const;

 
    const _Elem* narrow(
    const _Elem* first,  
    const _Elem* last,  
    char _Dflt,  
    char* dest) const;

 
    const _Elem* _Narrow_s(
    const _Elem* first,  
    const _Elem* last,  
    char _Dflt,  
    char* dest,  
    size_t dest_size) const;

 
    static locale::id& id;  
    explicit ctype(
    const mask* _Table = 0,  
    bool _Deletetable = false,  
    size_t _Refs = 0);

protected:  
    virtual ~ctype();
//other protected members  
};  
```  
  
## <a name="remarks"></a>Comentários  
 A especialização explícita é diferente da classe de modelo de várias maneiras:  
  
-   Um objeto de classe ctype < `char`> armazena um ponteiro para o primeiro elemento de uma tabela de máscara ctype, uma matriz de UCHAR_MAX + 1 elementos do tipo **ctype_base::mask**. Ele também armazena um objeto booliano que indica se a matriz deve ser excluída (usando `operator delete[]`) quando o ctype \< **Elem**> objeto é destruído.  
  
-   Seu único construtor público permite que você especifique **guia**, a tabela de máscara de ctype e **/DEL**, o objeto Boolean true se a matriz deve ser excluído quando ctype < `char`> objeto é destruído, bem como as referências de parâmetro de contagem de referência.  
  
-   A função de membro protegido **tabela** retorna a tabela de máscara ctype armazenado.  
  
-   O objeto de membro estático **table_size** Especifica o número mínimo de elementos em uma tabela de máscara ctype.  
  
-   A função de membro estático protegido **classic_table**(retorna a tabela de máscara ctype apropriado para a localidade "C".  
  
-   Não existem funções membro virtual protegida [do_is](../standard-library/ctype-class.md#ctype__do_is), [do_scan_is](../standard-library/ctype-class.md#ctype__do_scan_is), ou [do_scan_not](../standard-library/ctype-class.md#ctype__do_scan_not). As funções de membro público correspondente executam as operações equivalentes próprios.  
  
 As funções de membro [do_narrow](../standard-library/ctype-class.md#ctype__do_narrow) e [do_widen](../standard-library/ctype-class.md#ctype__do_widen) copiar elementos inalterados.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< localidade>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Classe facet](../Topic/facet%20Class.md)   
 [Classe ctype_base](../standard-library/ctype-base-class.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

