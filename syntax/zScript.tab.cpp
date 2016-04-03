// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 1 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:404

#include "global.h"

/// enable debug
#define YYDEBUG 1

#include "lex.yy.cpp"

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

#line 47 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 61 "zScript.tab.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 147 "zScript.tab.cpp" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 5:
#line 59 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yystack_[2].value.identifier)->value = *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[0].value.value);

                zInfo << (yystack_[2].value.identifier)->name << "=" << *(yylhs.value.value);
            }
#line 592 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 65 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(!Global::identifiersHash.contains((yystack_[2].value.identifier)->name)) {
                    std::cerr << (yystack_[2].value.identifier)->name.toStdString() << " is undefined!" << std::endl;
                    delete (yystack_[2].value.identifier);
                    YYERROR;
                }

                (yystack_[2].value.identifier)->value = *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[0].value.value);

                zInfo << (yystack_[2].value.identifier)->name << "=" << *(yylhs.value.value);
            }
#line 609 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 78 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(Global::identifiersHash.contains((yystack_[0].value.identifier)->name)) {
                    std::cerr << (yystack_[0].value.identifier)->name.constData() << " is defined!" << std::endl;
                    YYERROR;
                } else {
                    Global::identifiersHash[(yystack_[0].value.identifier)->name] = (yystack_[0].value.identifier);
                }

                (yylhs.value.identifier) = (yystack_[0].value.identifier);
            }
#line 624 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 88 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                zInfo << "function name: " << (yystack_[4].value.identifier)->name;
            }
#line 632 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 94 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(!Global::identifiersHash.contains((yystack_[0].value.identifier)->name)) {
                    std::cerr << (yystack_[0].value.identifier)->name.toStdString() << " is undefined!" << std::endl;
                    delete (yystack_[0].value.identifier);
                    YYERROR;
                }
                *(yylhs.value.value) = (yystack_[0].value.identifier)->value;
            }
#line 645 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 102 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) + *(yystack_[0].value.value);
            }
#line 653 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 105 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) - *(yystack_[0].value.value);
            }
#line 661 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 108 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) * *(yystack_[0].value.value);
            }
#line 669 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 111 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) / *(yystack_[0].value.value);
            }
#line 677 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 114 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) += *(yystack_[0].value.value);
            }
#line 685 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 117 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) -= *(yystack_[0].value.value);
            }
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 120 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) *= *(yystack_[0].value.value);
            }
#line 701 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 123 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) /= *(yystack_[0].value.value);
            }
#line 709 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 126 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) & *(yystack_[0].value.value);
            }
#line 717 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 129 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) | *(yystack_[0].value.value);
            }
#line 725 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 132 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) ^ *(yystack_[0].value.value);
            }
#line 733 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 135 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) % *(yystack_[0].value.value);
            }
#line 741 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 138 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) &= *(yystack_[0].value.value);
            }
#line 749 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 141 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) |= *(yystack_[0].value.value);
            }
#line 757 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 144 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) ^= *(yystack_[0].value.value);
            }
#line 765 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 147 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) %= *(yystack_[0].value.value);
            }
#line 773 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 150 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) == *(yystack_[0].value.value);
            }
#line 781 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 153 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) != *(yystack_[0].value.value);
            }
#line 789 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 156 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) <= *(yystack_[0].value.value);
            }
#line 797 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 159 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) >= *(yystack_[0].value.value);
            }
#line 805 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 162 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) && *(yystack_[0].value.value);
            }
#line 813 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 165 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[2].value.value) || *(yystack_[0].value.value);
            }
#line 821 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 168 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = ++ *(yystack_[0].value.value);
            }
#line 829 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 171 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[1].value.value)++;
            }
#line 837 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 174 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = -- *(yystack_[0].value.value);
            }
#line 845 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 177 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yylhs.value.value) = *(yystack_[1].value.value)--;
            }
#line 853 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 180 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { *(yylhs.value.value) = 0 - *(yystack_[0].value.value);}
#line 859 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 181 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { *(yylhs.value.value) = *(yystack_[0].value.value);}
#line 865 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 182 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { *(yylhs.value.value) = *(yystack_[1].value.value);}
#line 871 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 875 "zScript.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -34;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
     -34,     0,   -34,   -10,     1,   -16,   -34,   -33,    12,   -34,
      -1,     5,   -34,     5,     2,   -34,   -34,     5,     5,     5,
       5,     5,    74,    74,    -3,    -9,    -9,    -9,    -9,    39,
       5,     5,     5,     5,     5,     5,   -34,   -34,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,    18,   -34,   140,   140,   128,   128,
     104,   104,    74,    74,    74,    74,    74,    74,    74,    74,
     112,   112,   112,    63,    63,    -9,    -9,    -9,   -34
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     3,     0,     0,     7,
       0,     0,     4,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     6,     5,     0,    33,    35,    37,    38,     0,
       0,     0,     0,     0,     0,     0,    34,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    27,    28,    29,    30,
      31,    32,    18,    17,    15,    16,    26,    23,    24,    25,
      19,    20,    21,    12,    11,    13,    14,    22,     8
  };

  const signed char
  parser::yypgoto_[] =
  {
     -34,   -34,   -34,   -34,   -12
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     7,     8,    22
  };

  const unsigned char
  parser::yytable_[] =
  {
       2,    23,     9,     3,     4,    25,    26,    27,    28,    29,
      36,    37,     5,    10,    11,    12,    15,    16,    56,    57,
      58,    59,    60,    61,    17,    18,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    13,    19,    20,    14,    54,     0,     6,    24,
       0,    21,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    78,     0,
       0,     0,    46,    47,    48,     0,     0,    49,    50,    51,
      52,    53,    36,    37,     0,     0,    55,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    51,    52,    53,     0,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    30,    31,    32,
      33,     0,     0,    36,    37,    30,    31,    32,    33,     0,
       0,    36,    37,     0,     0,     0,     0,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    36,    37,     0,
      49,    50,    51,    52,    53,    32,    33,     0,     0,    36,
      37,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    53
  };

  const signed char
  parser::yycheck_[] =
  {
       0,    13,    12,     3,     4,    17,    18,    19,    20,    21,
      19,    20,    12,    12,    30,    48,    11,    12,    30,    31,
      32,    33,    34,    35,    19,    20,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    30,    38,    39,    46,    49,    -1,    48,    47,
      -1,    46,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    50,    -1,
      -1,    -1,    33,    34,    35,    -1,    -1,    38,    39,    40,
      41,    42,    19,    20,    -1,    -1,    47,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    40,    41,    42,    -1,    33,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    13,    14,    15,
      16,    -1,    -1,    19,    20,    13,    14,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    19,    20,    -1,
      38,    39,    40,    41,    42,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    52,     0,     3,     4,    12,    48,    53,    54,    12,
      12,    30,    48,    30,    46,    11,    12,    19,    20,    38,
      39,    46,    55,    55,    47,    55,    55,    55,    55,    55,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    33,    34,    35,    38,
      39,    40,    41,    42,    49,    47,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    50
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     3,     3,     3,     2,     6,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "VARIANT", "IDENTIFIER", "EQ", "NEQ",
  "LE", "GE", "AND", "OR", "ADDSELF", "SUBSELF", "DEQ", "MEQ", "AEQ",
  "SEQ", "MODEQ", "ANDEQ", "OREQ", "XOREQ", "','", "'='", "'?'", "':'",
  "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'", "'}'", "$accept",
  "start", "assign", "statement", "expression", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    54,    54,    55,    56,    59,    65,    78,    88,    93,
      94,   102,   105,   108,   111,   114,   117,   120,   123,   126,
     129,   132,   135,   138,   141,   144,   147,   150,   153,   156,
     159,   162,   165,   168,   171,   174,   177,   180,   181,   182
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    42,    33,     2,
      46,    47,    40,    39,    29,    38,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    48,
      37,    30,    36,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    34,    50,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    43
    };
    const unsigned int user_token_number_max_ = 284;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1269 "zScript.tab.cpp" // lalr1.cc:1167
#line 185 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


yyFlexLexer flexLexer;

int main()
{
    yy::parser parser;

    return parser.parse();
}

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;
}

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return flexLexer.yylex();
}
